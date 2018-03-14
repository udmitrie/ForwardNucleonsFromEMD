 //Created by Uliana Dmitrieva (uliana.dmitrieva@cern.ch) on 11/02/2018
 
#include <include/Parameters.h>
#include <include/Histograms_names.h>

//______________________________________________________________________
//FULL FITTING PROCEDURE
Double_t fit_hist(TH1D* hist,
int Et,
int npeaks,					//number of peaks in fit
int nfit,					//number of peaks for which cross-sections are calculated
const char *tfName,			//file name for writing results
char *detector,				
const char *condition,		//additional condition on histogram
int ifcondition)			//1 - if there is additional condition on histogram, else - 0

{
    //Fit hist histogram
        Int_t i=0;
        
	//Get fit parameters
		Double_t fitPar[15]= 0; 
        fitparameters(hist, Et, npeaks, fitPar);
		
		
	//Fit hist histogram       
		if (npeaks == 3) totalFit = new TF1("mCtotal","gausn(0)+gausn(3)+gausn(6)",0,3.5*fitPar[1]); 
		if (npeaks == 4) totalFit = new TF1("mCtotal","gausn(0)+gausn(3)+gausn(6)+gausn(9)",0,4.5*fitPar[1]);   
		if (npeaks == 5) totalFit = new TF1("mCtotal","gausn(0)+gausn(3)+gausn(6)+gausn(9)+gausn(12)",0,5.5*fitPar[1]);   
        totalFit->SetParameters(fitPar);  
       
	//fix parameters
        fixparameters(totalFit, fitPar);
        totalFit->SetLineColor(kBlue);
        hist->Fit(totalFit,"BR+");
       
	//print parameters into file
		ofstream fout(tfName, ios_base::app);
		if (ifcondition ==0) fout<<endl<<Form("Fit parameters for %s",detector)<<endl;
		if (ifcondition ==1) fout<<endl<<Form("Fit parameters for %s (%s)",detector, condition)<<endl;
		for (i=0;i<15;i++) fout<<totalFit->GetParName(i)<<"\t\t"<<totalFit->GetParameter(i)<<endl;
		
		
		
		//Cross-section calculations
	if ((detector == "ZNC") ||(detector == "ZNA"))  const char* particle = "neutrons";
	if ((detector == "ZPC") ||(detector == "ZPA")) 	const char* particle = "proton(s)";
	
	//Cross-section calculations  
	Double_t width=2*(hist->GetXaxis()->GetBinCenter(1));						
				
	Int_t ii=0;
				
	for (i=0;i<nfit;i++) { 
						
						nEv =(totalFit->GetParameter(ii))/width;
						nEr_syst = 1/sqrt(nEv);
						nEr_fit = (totalFit->GetParError(ii))/width/nEv;	
						
						sg = sED*nEv/totED;
						sgEr_fit = sg*(nEr_fit);
						sgEr_syst = sg*(nEr_syst);
						sgEr = sg*(sqrt(nEr_syst**2+(nEr_fit)**2));
										
						fout<<endl<<i+1<<Form(" %s in %s", particle, detector)<<endl;
						fout<<"\t"<<nEv<<" +- "<<nEr_fit*nEv<<" +- "<<nEr_syst*nEv<<"\t"<<" events"<<endl;
						fout<<"\t sigma = "<<sg<<" +- "<<sgEr_fit<<" +- "<<sgEr_syst<<"\t"<<" = "<<sg<<" +- "<<sgEr<<endl;
						ii=ii+3;
				
						}
	
	
	
		

		hist->GetXaxis()->SetRangeUser(0,Et);
		return hist;

}

//______________________________________________________________________
//FIT PARAMETERS FOR SEVERAL GAUSSIANS
Double_t fitparameters(TH1D* hist, int Et, int npeaks, Double_t *fitPar)
{
               
        //Emin
        hist->GetXaxis()->SetRangeUser(E0/4,E0);
        Emin=hist->GetBinCenter(hist->GetMinimumBin());   
		
		//Emax
        hist->GetXaxis()->SetRangeUser(Emin,1.5*E0);
        Emax=hist->GetBinCenter(hist->GetMaximumBin()); 
       
        hist->GetXaxis()->SetRangeUser(Emin,Et);
               
        gH1 = new TF1("gH1","gausn",Emin,1.51*Emax);
        gH1->SetParLimits(1,0.8*E0,1.2*E0);
        hist->Fit(gH1,"R");
        gH1->GetParameters(&fitPar[0]);  
      
        gH2 = new TF1("gH2","gausn",1.49*fitPar[1],2.51*fitPar[1]);
        gH2->FixParameter(1, 2*fitPar[1]);  
        gH2->FixParameter(2, sqrt(2)*fitPar[2]);     
        hist->Fit(gH2,"BR+");
        gH2->GetParameters(&fitPar[3]);   
       
        gH3 = new TF1("gH3","gausn",2.49*fitPar[1],3.51*fitPar[1]);
        gH3->FixParameter(1, 3*fitPar[1]);    
        gH3->FixParameter(2, sqrt(3)*fitPar[2]);       
        hist->Fit(gH3,"BR+");
        gH3->GetParameters(&fitPar[6]);   

        if (npeaks>3) {
        gH4 = new TF1("gH4","gausn",3.49*fitPar[1],4.51*fitPar[1]);
        gH4->FixParameter(1, 4*fitPar[1]);    
        gH4->FixParameter(2, sqrt(4)*fitPar[2]);     
        hist->Fit(gH4,"BR+");
        gH4->GetParameters(&fitPar[9]);   
		}
       
       if (npeaks>4) {
        gH5 = new TF1("gH5","gausn",4.49*fitPar[1],5.51*fitPar[1]);
        gH5->FixParameter(1, 5*fitPar[1]);  
        gH5->FixParameter(2, sqrt(5)*fitPar[2]);       
        hist->Fit(gH5,"BR+");
        gH5->GetParameters(&fitPar[12]); 
        return fitPar;
		}
}


//FIX MEAN AND SIGMA AND SET NAMES FOR TOTALFIT FUNCTION
Double_t fixparameters(TF1* totalFit, Double_t *fitPar)
{
	
	Int_t p=1;      
	Int_t i=0;
	for (i=0;i<15;i++) {  
						 if ((i==1)||(i==4)||(i==7)||(i==10)||(i==13))
							{   totalFit->FixParameter(i, fitPar[i]);
							totalFit->SetParName(i, Form("Mean_%d",p));
							} 
								
						if ((i==0)||(i==3)||(i==6)||(i==9)||(i==12))
							{    
							totalFit->SetParName(i, Form("Const_%d",p));
							} 
						
						if ((i==2)||(i==5)||(i==8)||(i==11)||(i==14))
							{   
							totalFit->SetParName(i, Form("Sigma_%d",p));
							totalFit->FixParameter(i, fitPar[i]);
							p=p+1;
							} 
						}

	return totalFit;
}


//______________________________________________________________________
//RETURNS MEAN OF THE FIRST PEAK
Double_t getE0(TH1D* hist,
int Et,
int npeaks
)			

{
		Int_t i=0;
        
    //Get fit parameters
		Double_t fitPar[15]= 0; 
        fitparameters(hist, Et, npeaks, fitPar);      fitparameters(hist, Et, npeaks, fitPar);
		
	//E0 real energy (mean of the first peak)       
     	Double_t E0_real = fitPar[1];
		return E0_real;

}

//______________________________________________________________________
//RETURNS SIGMA OF THE FIRST PEAK
Double_t getSigma(TH1D* hist,
int Et,
int npeaks
)			

{
		Int_t i=0;
        
    //Get fit parameters
		Double_t fitPar[15]= 0; 
        fitparameters(hist, Et, npeaks, fitPar);      fitparameters(hist, Et, npeaks, fitPar);
		
	//E0 real energy (mean of the first peak)       
     	Double_t E0_real = fitPar[2];
		return E0_real;

}


