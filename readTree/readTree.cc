/******************************************************************
 * Copyright(c) 1998-2018, ALICE Experiment at CERN, All rights reserved.		*
 *																														*
 * Contributors are mentioned in the code where appropriate. 								*
 *																														*
 * Permission to use, copy, modify and distribute this software and its					*
 * documentation strictly for non-commercial purposes is hereby granted			*
 * without fee, provided that the above copyright notice appears in all copies		*
 * and that both the copyright notice and this permission notice appear in the		*
 * supporting documentation. The authors make no claims about the suitability	*
 * of this software for any purpose. It is provided "as is" without express or		*
 * implied warranty.																							*
 ******************************************************************/

/******************************************************************
 * 1D histograms representing energy spectra in neutron and proton ZDCs and	*
 * 2D histograms representing correlations between energies in neutron ZDCs		*
 * at A and C sides, energies in neutron and proton ZDCs at each side filled		*
 * here on the basis of a tree created by AliAnalysisTaskZDCTree class				* 
 * (https://github.com/alisw/AliPhysics/tree/master/PWGUD/UPC).					*
 * AnalysiResults_full.root file is created as the result of running this macros.		*
 ******************************************************************/
 
 // Created by Uliana Dmitrieva (uliana.dmitrieva@cern.ch) on 11/02/2018

   
#include <iostream>
#include <stdio.h>
#include <string.h>
# include <fstream>
# include "Riostream.h"

#include <TH1D.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TFile.h>
#include <TList.h>
#include <TTree.h>
Int_t readTree()
{
	  // NEW HISTOGRAMS
	  
	  //SPECTRA
	  TH1D *fZNCSpectrum = new TH1D("fZNCSpectrum", "", 2400,0., 240000.);
	  fZNCSpectrum->SetXTitle("E_{ZNC} (GeV)");
	  
	  TH1D *fZNASpectrum = new TH1D("fZNASpectrum", "", 2400,0., 240000.) ;
	  fZNASpectrum->SetXTitle("E_{ZNA} (GeV)");
	  
	  TH1D *fZPCSpectrum = new TH1D("fZPCSpectrum", "", 800,0., 80000.) ;
	  fZPCSpectrum->SetXTitle("E_{ZPC} (GeV)");
	  	  
	  TH1D *fZPASpectrum = new TH1D("fZPASpectrum", "", 800,0., 80000.) ;
	  fZPASpectrum->SetXTitle("E_{ZPA} (GeV)");
	 
	  TH1D *fZEM1Spectrum = new TH1D("fZEM1Spectrum", "", 200,0., 2000.);
	  fZEM1Spectrum->SetXTitle("ZEM amplitide (a.u.)");
	  
	  TH1D *fZEM2Spectrum = new TH1D("fZEM2Spectrum", "", 200,0., 2000.);
	  fZEM2Spectrum->SetXTitle("ZEM amplitide (a.u.)");
	  
	  //EM SPECTRA
	  TH1D *fZNCSpectrum_singleminmutualEMD = new TH1D("fZNCSpectrum_singleminmutualEMD", "", 2400,0., 240000.);
	  fZNCSpectrum_singleminmutualEMD->SetXTitle("E_{ZNC} (GeV)");
	  
	  TH1D *fZNASpectrum_singleminmutualEMD = new TH1D("fZNASpectrum_singleminmutualEMD", "", 2400,0., 240000.) ;
	  fZNASpectrum_singleminmutualEMD->SetXTitle("E_{ZNA} (GeV)");
	  
	  TH1D *fZNCSpectrumEM = new TH1D("fZNCSpectrumEM", "", 2400,0., 240000.);
	  fZNCSpectrumEM->SetXTitle("E_{ZNC} (GeV)");
	  
	  TH1D *fZNASpectrumEM = new TH1D("fZNASpectrumEM", "", 2400,0., 240000.) ;
	  fZNASpectrumEM->SetXTitle("E_{ZNA} (GeV)");
	  
	  TH1D *fZPCSpectrumEM = new TH1D("fZPCSpectrumEM", "", 800,0., 80000.) ;
	  fZPCSpectrumEM->SetXTitle("E_{ZPC} (GeV)");
	  
	  TH1D *fZPASpectrumEM = new TH1D("fZPASpectrumEM", "", 800,0., 80000.) ;
	  fZPASpectrumEM->SetXTitle("E_{ZPA} (GeV)");
	  
	  TH1D *fZNCSpectrumEM_0p = new TH1D("fZNCSpectrumEM_0p", "", 2400,0., 240000.);
	  fZNCSpectrumEM_0p->SetXTitle("E_{ZNC} (GeV)");
	  
	  TH1D *fZNASpectrumEM_0p = new TH1D("fZNASpectrumEM_0p", "", 2400,0., 240000.) ;
	  fZNASpectrumEM_0p->SetXTitle("E_{ZNA} (GeV)");
	 
	  TH1D *fZPASpectrumEM_3n = new TH1D("fZPASpectrumEM_3n", "", 800,0., 80000.) ;
	  fZPASpectrumEM_3n->SetXTitle("E_{ZPA} (GeV)");
	  
	  TH1D *fZPCSpectrumEM_3n = new TH1D("fZPCSpectrumEM_3n", "", 800,0., 80000.) ;
	  fZPCSpectrumEM_3n->SetXTitle("E_{ZPC} (GeV)");
	  
	  TH1D *fZPASpectrumEM_1n = new TH1D("fZPASpectrumEM_1n", "", 800,0., 80000.) ;
	  fZPASpectrumEM_1n->SetXTitle("E_{ZPA} (GeV)");
	  
	  TH1D *fZPCSpectrumEM_1n = new TH1D("fZPCSpectrumEM_1n", "", 800,0., 80000.) ;
	  fZPCSpectrumEM_1n->SetXTitle("E_{ZPC} (GeV)");
	  
	  //EM CORRELATIONS
	  TH2F *fCorrNCvsNA = new TH2F("fCorrNAvsNC","",2400,0,240000,2400,0,240000);
	  fCorrNCvsNA->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsNA->SetYTitle("E_{ZNA} (GeV)");
	  fCorrNCvsNA->SetOption("Colz");
	 
	  TH2F *fCorrNCvsPC = new TH2F("fCorrPCvsNC","",2400,0,240000,2400,0,240000);
	  fCorrNCvsPC->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsPC->SetYTitle("E_{ZPC} (GeV)");
	  fCorrNCvsPC->SetOption("Colz");
	  
	  TH2F *fCorrNAvsPA = new TH2F("fCorrPAvsNA","",2400,0,240000,2400,0,240000);
	  fCorrNAvsPA->SetXTitle("E_{ZNA} (GeV)");
	  fCorrNAvsPA->SetYTitle("E_{ZPA} (GeV)");
	  fCorrNAvsPA->SetOption("Colz");
	 
	  TH2F *fCorrNCvsNAem = new TH2F("fCorrNAvsNCem","",2400,0,240000,2400,0,240000);
	  fCorrNCvsNAem->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsNAem->SetYTitle("E_{ZNA} (GeV)");
	  fCorrNCvsNAem->SetOption("Colz");
	  
	  TH2F *fCorrNCvsPCem = new TH2F("fCorrPCvsNCem","",2400,0,240000,2400,0,240000);
	  fCorrNCvsPCem->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsPCem->SetYTitle("E_{ZPC} (GeV)");
	  fCorrNCvsPCem->SetOption("Colz");
	  
	  TH2F *fCorrNAvsPAem = new TH2F("fCorrPAvsNAem","",2400,0,240000,2400,0,240000);
	  fCorrNAvsPAem->SetXTitle("E_{ZNA} (GeV)");
	  fCorrNAvsPAem->SetYTitle("E_{ZPA} (GeV)");
	  fCorrNAvsPAem->SetOption("Colz");
	  
	  TH2F *fCorrNCvsPCem_only1side = new TH2F("fCorrPCvsNCem_single","",2400,0,240000,2400,0,240000);
	  fCorrNCvsPCem_only1side->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsPCem_only1side->SetYTitle("E_{ZPC} (GeV)");
	  fCorrNCvsPCem_only1side->SetOption("Colz");
	  
	  TH2F *fCorrNAvsPAem_only1side = new TH2F("fCorrPAvsNAem_single","",2400,0,240000,2400,0,240000);
	  fCorrNAvsPAem_only1side->SetXTitle("E_{ZNA} (GeV)");
	  fCorrNAvsPAem_only1side->SetYTitle("E_{ZPA} (GeV)");
	  fCorrNAvsPAem_only1side->SetOption("Colz");

	//HADRONIC CORRELATIONS
	  TH2F *fCorrNCvsNAh = new TH2F("fCorrNAvsNCh","",2400,0,240000,2400,0,240000);
	  fCorrNCvsNAh->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsNAh->SetYTitle("E_{ZNA} (GeV)");
	  fCorrNCvsNAh->SetOption("Colz");
	  
	  TH2F *fCorrNCvsPCh = new TH2F("fCorrPCvsNCh","",2400,0,240000,2400,0,240000);
	  fCorrNCvsPCh->SetXTitle("E_{ZNC} (GeV)");
	  fCorrNCvsPCh->SetYTitle("E_{ZPC} (GeV)");
	  fCorrNCvsPCh->SetOption("Colz");
	  
	  TH2F *fCorrNAvsPAh = new TH2F("fCorrPAvsNAh","",2400,0,240000,2400,0,240000);
	  fCorrNAvsPAh->SetXTitle("E_{ZNA} (GeV)");
	  fCorrNAvsPAh->SetYTitle("E_{ZPA} (GeV)");
	  fCorrNAvsPAh->SetOption("Colz");
	  
	  TH2F *fCorrZNAvsZEM = new TH2F ("fCorrZNAvsZEM","",100,0,2000,3000,0, 300000);
	  fCorrZNAvsZEM->SetXTitle("ZEM amplitide (a.u.)");
	  fCorrZNAvsZEM->SetYTitle("E_{ZNA} (GeV)");
	  fCorrZNAvsZEM->SetOption("Colz");
	  
	  TH2F *fCorrZPAvsZEM = new TH2F ("fCorrZPAvsZEM","",100,0,2000,3000,0, 300000);
	  fCorrZPAvsZEM->SetXTitle("ZEM amplitide (a.u.)");
	  fCorrZPAvsZEM->SetYTitle("E_{ZPA} (GeV)");
	  fCorrZPAvsZEM->SetOption("Colz");	
	  
	  //TDC INFO
	  TH1D *fTDCZNC = new TH1D("fTDCZNC","TDC_{ZNC}",60,-30.,30.);
	  fTDCZNC->GetXaxis()->SetTitle("TDC_{ZNC} (ns)");
	
	  TH1D *fTDCZNA = new TH1D("fTDCZNA","TDC_{ZNA}",60,-30.,30.);
	  fTDCZNA->GetXaxis()->SetTitle("TDC_{ZNA} (ns)");
	 
	  TH2F *fNSumvsDiff = new TH2F("fNSumvsDiff","ZN TDC sum vs. diff", 10000,-500,500,1000,-100,100);
	  fNSumvsDiff->GetYaxis()->SetTitle("TDC_{ZNC}-TDC_{ZNA} (ns)");
	  fNSumvsDiff->GetXaxis()->SetTitle("TDC_{ZNC}+TDC_{ZNA} (ns)");

	
//______________________________________________________________________________________________  
	//READ TREE
	cout<<endl<<"BEGIN"<<endl;
	
	Int_t EMD = 0;
	Int_t nEntries;
	
	const char* FileName = "AnalysisResults.root";
	const char* ListName = "/ZDCTreeTask/fOutput";
	const char* TreeName = "fZDCTree";
		
    TFile* inFile=new TFile(FileName);
	TList* List=(TList*) inFile->Get(ListName);
	TTree* Tree=(TTree*) List->FindObject(TreeName);
		
	Float_t zncEnergy, znaEnergy, zpcEnergy, zpaEnergy, zem1Energy, zem2Energy;
	Float_t znctower[5], znatower[5], zpctower[5], zpatower[5];
	Float_t zncTDC[4], znaTDC[4], zpcTDC[4], zpaTDC[4];
	Bool_t isZEM1, isZEM2, isZNC, isZPC, isZNA, isZPA,  is1ZED, isCTRUE;
		
	Tree->SetBranchAddress("zncEnergy",&zncEnergy);
	Tree->SetBranchAddress("znaEnergy",&znaEnergy);
	Tree->SetBranchAddress("zpcEnergy",&zpcEnergy);
	Tree->SetBranchAddress("zpaEnergy",&zpaEnergy);
	Tree->SetBranchAddress("zem1Energy",&zem1Energy);
	Tree->SetBranchAddress("zem2Energy",&zem2Energy);
	Tree->SetBranchAddress("isZEM1",&isZEM1);
	Tree->SetBranchAddress("isZEM2",&isZEM2);
	Tree->SetBranchAddress("isZNC",&isZNC);
	Tree->SetBranchAddress("isZPC",&isZPC);
	Tree->SetBranchAddress("isZNA",&isZNA);
	Tree->SetBranchAddress("isZPA",&isZPA);
	Tree->SetBranchAddress("is1ZED",&is1ZED);
	Tree->SetBranchAddress("isCTRUE",&isCTRUE);
	
	Tree->SetBranchAddress("znctower",&znctower);
	Tree->SetBranchAddress("znatower",&znatower);
	Tree->SetBranchAddress("zpctower",&zpctower);
	Tree->SetBranchAddress("zpatower",&zpatower);
	
	Tree->SetBranchAddress("zncTDC",&zncTDC);
	Tree->SetBranchAddress("znaTDC",&znaTDC);
	Tree->SetBranchAddress("zpcTDC",&zpcTDC);
	Tree->SetBranchAddress("zpaTDC",&zpaTDC);

		nEntries = Tree->GetEntries();
		cout<<"entries "<<nEntries<<endl;
		
		for (Int_t i = 0; i<nEntries; i++) 
		
		{
		  Tree->GetEntry(i);  //the object event has been filled at this point
		
//Get C1ZED-B trigger events
		  if(is1ZED) 
			 {
				 
			 fZNCSpectrum->Fill(zncEnergy);
			 fZNASpectrum->Fill(znaEnergy);
			 fZPCSpectrum->Fill(zpcEnergy);
			 fZPASpectrum->Fill(zpaEnergy);
			 fZEM1Spectrum->Fill(zem1Energy);
			 fZEM2Spectrum->Fill(zem2Energy);
			 
			 
			 //TDC
			Float_t tdcNC=999., tdcNA=999;
			 Float_t tdcNSum=999., tdcNDiff=999.;

			 for(int k=0; k<4; k++){
							if(zncTDC[k] != 999.){
							  tdcNC = zncTDC[k];
							  fTDCZNC->Fill(tdcNC);
							 }
							 if(znaTDC[k] !=999.){
								tdcNA = znaTDC[k];
								fTDCZNA->Fill(tdcNA);
							 }

						tdcNSum = tdcNC + tdcNA ;
						tdcNDiff= tdcNC -tdcNA ;
						
						if(tdcNSum<999. && tdcNDiff<999.)  fNSumvsDiff->Fill(tdcNSum, tdcNDiff);
			 }
						 
			 
				 // Correlations
				
				 fCorrNCvsNA->Fill(zncEnergy,znaEnergy); 
				 if (isZPC) fCorrNCvsPC->Fill(zncEnergy,zpcEnergy);  
				 if (isZPA) fCorrNAvsPA->Fill(znaEnergy,zpaEnergy);  
				 
				 
				 //single minus mutual EMD 
				if (isZNC && !isZNA)	fZNCSpectrum_singleminmutualEMD->Fill(zncEnergy);
				if (isZNA && !isZNC)	fZNASpectrum_singleminmutualEMD->Fill(znaEnergy);
							
				  //EM evnts
				 if(!isZEM1 && !isZEM2)
							{
								
											fCorrNCvsNAem->Fill(zncEnergy,znaEnergy); 
								if (isZNC && isZPC)	fCorrNCvsPCem->Fill(zncEnergy,zpcEnergy);  
								if (isZNA && isZPA)	fCorrNAvsPAem->Fill(znaEnergy,zpaEnergy); 
								
								if (isZPC)	fCorrNCvsPCem_only1side->Fill(zncEnergy,zpcEnergy);  
								if (isZPA)	fCorrNAvsPAem_only1side->Fill(znaEnergy,zpaEnergy); 
								
								if (isZNC)	fZNCSpectrumEM->Fill(zncEnergy);
								if (isZNA)	fZNASpectrumEM->Fill(znaEnergy);
								if (isZPC)	fZPCSpectrumEM->Fill(zpcEnergy);
								if (isZPA)	fZPASpectrumEM->Fill(zpaEnergy);
				
							
								if (isZNC && !isZPC)	fZNCSpectrumEM_0p->Fill(zncEnergy);
								if (isZNA && !isZPA)	fZNASpectrumEM_0p->Fill(znaEnergy);
								
								if (isZPC && zncEnergy<8200)	fZPCSpectrumEM_3n->Fill(zpcEnergy);
								if (isZPA && znaEnergy<8200)	fZPASpectrumEM_3n->Fill(zpaEnergy);
								
								if (isZPC && isZNC)	fZPCSpectrumEM_1n->Fill(zpcEnergy);
								if (isZPA && isZNA)	fZPASpectrumEM_1n->Fill(zpaEnergy);
							
								
								EMD = EMD+1; 
				
							}
				  
				 if(isZEM1 || isZEM2)
							{
								
											fCorrNCvsNAh->Fill(zncEnergy,znaEnergy); 
								if (isZPC) 	fCorrNCvsPCh->Fill(zncEnergy,zpcEnergy);  
								if (isZPA)	fCorrNAvsPAh->Fill(znaEnergy,zpaEnergy); 
								
								Float_t sumZEM = zem1Energy+zem2Energy;
								
								//ZNAvsZEM and ZPAvsZEM Correlations
								fCorrZNAvsZEM->Fill(sumZEM,znaEnergy); 
								fCorrZPAvsZEM->Fill(sumZEM,zpaEnergy); 
							}
			}
			 
		}
		cout<<"out of file"<<endl;
	

//______________________________________________________________________________________________  

	// WRITE HISTOGRAMS INTO .root
	cout<<endl<<"WRITE HISTOGRAMS"<<endl;
	TFile* outFile = new TFile("AnalysisResults_full.root", "RECREATE");
    fZNCSpectrum->Write();
    fZNASpectrum->Write();
    fZNCSpectrumEM->Write();
    fZNASpectrumEM->Write();
    fZNCSpectrum_singleminmutualEMD->Write();
    fZNASpectrum_singleminmutualEMD->Write();
    fZNCSpectrumEM_0p->Write();
    fZNASpectrumEM_0p->Write();
    fZPCSpectrum->Write();
    fZPASpectrum->Write();
    fZPCSpectrumEM->Write();
    fZPASpectrumEM->Write();
    fZPCSpectrumEM_3n->Write();
    fZPASpectrumEM_3n->Write();
    fZPCSpectrumEM_1n->Write();
    fZPASpectrumEM_1n->Write();
    fCorrNCvsNA->Write();
	fCorrNCvsPC->Write();
	fCorrNAvsPA->Write(); 
	fCorrNCvsNAem->Write();
	fCorrNCvsPCem->Write();
	fCorrNAvsPAem->Write(); 
	fCorrNCvsPCem_only1side->Write();
	fCorrNAvsPAem_only1side->Write(); 
	fCorrNCvsNAh->Write();
	fCorrNCvsPCh->Write();
	fCorrNAvsPAh->Write(); 
	fCorrZNAvsZEM->Write();
	fCorrZPAvsZEM->Write();
	fNSumvsDiff->Write();
    outFile->Close();
    outFile->Delete();
    
    cout<<endl<<"Number of EMD events: "<<EMD<<endl;
//______________________________________________________________________________________________  

}
