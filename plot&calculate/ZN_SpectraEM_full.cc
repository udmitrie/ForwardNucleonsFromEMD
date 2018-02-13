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
 
 //Created by Uliana Dmitrieva (uliana.dmitrieva@cern.ch) on 11/02/2018

	#include <include/Parameters.h>
	#include <include/Variables.h>
	#include <include/Histograms_names.h>
	#include <include/Fit.h>
    using namespace std;
    
    void ZN_SpectraEM_full()
    {  
		const char* tfName = "results/ZN_SpectraEM_full.txt";
		const char* PlotName = "results/ZN_SpectraEM_full.eps";
		
	//Create file for printing results   
		ofstream fout(tfName, ios_base::trunc);
//______________________________________________________________________
		
	//energy threshold 
		Et=9000;
	
	//fit parameters	
		npeaks = 5;
		nfit = 4;
//______________________________________________________________________       
// DRAW SETTINGS     
	       
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
		leg1 = new TLegend(0.3,0.74,0.65,0.86);
		leg1->SetTextSize(0.03);
		leg2 = new TLegend(0.3,0.74,0.65,0.86);
		leg2->SetTextSize(0.03);
		
//______________________________________________________________________		       
	//ZNC Spectrum          
		pad->cd(1);
		
	//Fit for ZNC
		fit_hist(hZNC_em, Et, npeaks, nfit, tfName, "ZNC", condition, 0);
		
	//Draw hZNC_em 
		hZNC_em->Draw();
		pad->Update();  

//______________________________________________________________________     
	//ZNA Spectrum          
		pad->cd(2);    
		
	//Fit for ZNA
		fit_hist(hZNA_em,  Et, npeaks, nfit, tfName, "ZNA", condition, 0);
		
	//Draw hZNA_em 
		hZNA_em->Draw();
		pad->Update();  
//______________________________________________________________________   
  
	pad->Print(PlotName);
        
    }

