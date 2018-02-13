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
 * Plot spectra in neutron ZDCs providing that there is exactly one proton in		*
 * proton ZDC by projecting 2D histos from AnalysiResults_full.root					*
 ******************************************************************/
 
 //Created by Uliana Dmitrieva (uliana.dmitrieva@cern.ch) on 11/02/2018

	#include <include/Parameters.h>
	#include <include/Variables.h>
	#include <include/Histograms_names.h>
	#include <include/Fit.h>
    using namespace std;

    void Projections_2p()

    {  
		const char* tfName = "results/Projections_2p.txt";
		const char* PlotName = "results/Projections_2p.eps";
		
	//Create file for printing results   
		ofstream fout(tfName, ios_base::trunc);
//______________________________________________________________________
		
	//energy threshold 
		Et=12000;
	
	//fit parameters	
		npeaks = 3;
		nfit = 3;
//______________________________________________________________________       
       	       
	//StatBox parameters
        gStyle->SetStatY(0.9);                
        gStyle->SetStatX(0.9); 
        
        gStyle->SetOptStat("ne");
        
	//Make a canva
        TCanvas* c=new TCanvas("c");
        c->SetCanvasSize(900,450);
        
	//Make a pad        
        TPad* pad = new TPad("pad","The pad with the historgrams",0.0,0.0,1.0,1.0,21);
        pad->SetBorderMode(0);
        pad->SetFillColor(kWhite);
        pad->SetTickx(); 
        pad->SetTicky(); 
        pad->Draw(); 
        pad->Divide(2,1);  

	//Make legend
		leg1 = new TLegend(0.2,0.75,0.58,0.85);
		leg1->SetTextSize(0.03);
		leg2 = new TLegend(0.2,0.75,0.58,0.85);
		leg2->SetTextSize(0.03);
		
//______________________________________________________________________
//PROJECTION AND FIT FOR 1p in ZPC

		pad->cd(1);
        
	//Peak position ad its width  
		E0_real = getE0(hZPC_3n, Et, npeaks);
		Sigma0 = getSigma(hZPC_3n, Et, npeaks);
		
		en=hPCvsNC_em->GetYaxis()->FindBin(2*E0_real-2*sqrt(2)*Sigma0);
		ev=hPCvsNC_em->GetYaxis()->FindBin(2*E0_real+2*sqrt(2)*Sigma0);
	
	//Projection
	TH1D *hZPCvsZNC_2p = hPCvsNC_em->ProjectionX("ZPCvsZNC_2p", en, ev); // where firstYbin = en and lastYbin = ev
	
    //Fit
		condition = "2 protons in ZPC";
		fit_hist(hZPCvsZNC_2p, Et, npeaks, nfit, tfName, "ZNC", condition, 1);
		
	//Draw
	
		hZPCvsZNC_2p->Draw();
		
		
	//Legend
		leg1->AddEntry((TObject*)0, condition, "");
       // leg1->AddEntry((TObject*)0,  "for projection in [E_{0}-2#sigma, E_{0}+2#sigma]", "");
        leg1->Draw();
		
		pad->Update();  
        			
	  
 //______________________________________________________________________ 
//PROJECTION AND FIT FOR 1p in ZPA

		pad->cd(2);
        
	//Peak position ad its width  
	E0_real = getE0(hZPA_3n, Et, npeaks);
	Sigma0 = getSigma(hZPA_3n, Et, npeaks);
          
          
        en=hPAvsNA_em->GetYaxis()->FindBin(2*E0_real-2*sqrt(2)*Sigma0);
        ev=hPAvsNA_em->GetYaxis()->FindBin(2*E0_real+2*sqrt(2)*Sigma0);
   
	//Projection        
        TH1D *hZPAvsZNA_2p = hPAvsNA_em->ProjectionX("ZPAvsZNA_2p", en, ev); // where firstYbin = en and lastYbin = ev
        
        
    //Fit
		condition = "2 protons in ZPA";
		fit_hist(hZPAvsZNA_2p, Et, npeaks, nfit, tfName, "ZNA", condition, 1);
		
	//Draw
		hZPAvsZNA_2p->Draw();
		
	//Legend
		leg2->AddEntry((TObject*)0, condition, "");
        //leg2->AddEntry((TObject*)0,  "for projection in [E_{0}-2#sigma, E_{0}+2#sigma]", "");
        leg2->Draw();
		
		pad->Update(); 
//______________________________________________________________________  
 
        pad->Print(PlotName);
        
    }

