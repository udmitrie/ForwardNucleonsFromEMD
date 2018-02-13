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

void CorrelationsZDCvsZEM()

{  

		const char* PlotName = "results/CorrelationsZDCvsZEM.eps";
//__________________________________________________________       
// DRAW SETTINGS
	set_plot_style();

	//stat.box settings
  gROOT->ForceStyle();
  gStyle->SetStatY(0.9);        
  gStyle->SetStatX(0.9); 
  //gStyle->SetStatW(0.2);        
  gStyle->SetStatH(0.15);  
  //gStyle->SetOptStat(110011);
  //gStyle->SetPaintTextFormat("0.2f");
    
  // Make a canva and a pad
  TCanvas* c=new TCanvas("c");
  c->SetCanvasSize(900,450);
  pad = new TPad("pad","The pad with the historgram",0.0,0.0,1.0,1.0,21);
  pad->SetBorderMode(0);
  pad->SetBorderSize(100);
  pad->SetFillColor(kWhite);
  pad->SetTickx(100); 
  pad->SetTicky(100); 
  pad->Draw(); 
  pad->Divide(2,1);
	//Make legend
		leg1 = new TLegend(0.3,0.74,0.65,0.86);
		leg1->SetTextSize(0.03);
		leg2 = new TLegend(0.3,0.74,0.65,0.86);
		leg2->SetTextSize(0.03);
//______________________________________________________________________		       
	//ZNA Correlations
		pad->cd(1);
		
		gPad->SetLogz(1);
		pad->GetPad(1)->SetLeftMargin(.15);
		hNAvsEM->SetMinimum(1);
		hNAvsEM->GetXaxis()->SetLabelSize(0.03);
		hNAvsEM->GetYaxis()->SetLabelSize(0.03);
		hNAvsEM->GetXaxis()->SetTitleSize(0.045);
		hNAvsEM->GetYaxis()->SetTitleSize(0.045);
		hNAvsEM->GetYaxis()->SetTitleOffset(1.35);
		hNAvsEM->GetZaxis()->SetLabelOffset(0.0);
		hNAvsEM->Draw();
		
		leg1->AddEntry((TObject*)0, "NAvsEM", "");
		//leg1->Draw();
//______________________________________________________________________		       
	//ZPA Correlations
		pad->cd(2);
		
		gPad->SetLogz(1);
		pad->GetPad(1)->SetLeftMargin(.15);
		hPAvsEM->SetMinimum(1);
		hPAvsEM->GetXaxis()->SetLabelSize(0.03);
		hPAvsEM->GetYaxis()->SetLabelSize(0.03);
		hPAvsEM->GetXaxis()->SetTitleSize(0.045);
		hPAvsEM->GetYaxis()->SetTitleSize(0.045);
		hPAvsEM->GetYaxis()->SetTitleOffset(1.35);
		hPAvsEM->GetZaxis()->SetLabelOffset(0.0);
		hPAvsEM->Draw();
	
		leg2->AddEntry((TObject*)0, "PA	vsEM", "");
		//leg2->Draw();
 //_______________________ 

  //set energy ranges
 
  hNAvsEM->GetXaxis()->SetRangeUser(0, maxE_ZEM);
  hNAvsEM->GetYaxis()->SetRangeUser(0, maxE_ZN);
  hPAvsEM->GetXaxis()->SetRangeUser(0, maxE_ZEM);
  hPAvsEM->GetYaxis()->SetRangeUser(0, maxE_ZP);
 
//______________________________________________________________________
 
  pad->Update();
  pad->Print(PlotName);
  
}

