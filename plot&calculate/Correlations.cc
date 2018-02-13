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

void Correlations()
{  
 
  const char* PlotName = "results/Correlations.eps";
  
  //energy thresholds 
  Int_t Et_ZN_nn=150000;
  Int_t Et_ZN_np=10000;
  Int_t Et_ZP=10000;



//______________________________________________________________________
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
  c->SetCanvasSize(1300,400);
  pad = new TPad("pad","The pad with the historgram",0.0,0.0,1.0,1.0,21);
  pad->SetBorderMode(0);
  pad->SetBorderSize(100);
  pad->SetFillColor(kWhite);
  pad->SetTickx(100); 
  pad->SetTicky(100); 
  pad->Draw(); 
  pad->Divide(3,1);
 
  //legend settings 
  leg1 = new TLegend(0.25,0.77,0.65,0.85);
  leg1->SetTextSize(0.035);
  leg2 = new TLegend(0.25,0.77,0.65,0.85);
  leg2->SetTextSize(0.035);
  leg3 = new TLegend(0.25,0.77,0.65,0.85);
  leg3->SetTextSize(0.035);
  
//______________________________________________________________________
//DRAW
		 
  pad->cd(1);
  pad->GetPad(1)->SetLeftMargin(.15);
  gPad->SetLogz(1);
  hNAvsNC->SetMinimum(1);
  hNAvsNC->GetXaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hNAvsNC->GetYaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hNAvsNC->GetXaxis()->SetLabelSize(0.03);
  hNAvsNC->GetYaxis()->SetLabelSize(0.03);
  hNAvsNC->GetXaxis()->SetTitleSize(0.045);
  hNAvsNC->GetYaxis()->SetTitleSize(0.045);
  hNAvsNC->GetYaxis()->SetTitleOffset(1.8);
  hNAvsNC->GetZaxis()->SetLabelOffset(0.0);
  hNAvsNC->Draw();
  
  leg1->AddEntry((TObject*)0, "ZNC vs. ZNA", "");
  leg1->Draw();
  pad->Update();
  
//_______________________
		  
  pad->cd(2);
  gPad->SetLogz(1);
  pad->GetPad(2)->SetLeftMargin(0.15);

  hPCvsNC->SetMinimum(1);
  hPCvsNC->GetXaxis()->SetLabelSize(0.03);
  hPCvsNC->GetXaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hPCvsNC->GetYaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hPCvsNC->GetYaxis()->SetLabelSize(0.03);
  hPCvsNC->GetXaxis()->SetTitleSize(0.045);
  hPCvsNC->GetYaxis()->SetTitleSize(0.045);
  hPCvsNC->GetYaxis()->SetTitleOffset(1.8);
  hPCvsNC->GetZaxis()->SetLabelOffset(0.0);
  hPCvsNC->Draw();
  
  leg2->AddEntry((TObject*)0, "	ZPC vs. ZNC", "");
  leg2->Draw();

//_______________________ 

  pad->cd(3);
  gPad->SetLogz(1);
  pad->GetPad(3)->SetLeftMargin(.15);
  
  hPAvsNA->SetMinimum(1);
  hPAvsNA->GetXaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hPAvsNA->GetYaxis()->SetNdivisions(5, 5, 0, kTRUE);
  hPAvsNA->GetXaxis()->SetLabelSize(0.03);
  hPAvsNA->GetYaxis()->SetLabelSize(0.03);
  hPAvsNA->GetXaxis()->SetTitleSize(0.045);
  hPAvsNA->GetYaxis()->SetTitleSize(0.045);
  hPAvsNA->GetYaxis()->SetTitleOffset(1.8);
  hPAvsNA->GetZaxis()->SetLabelOffset(0.0);  
  hPAvsNA->Draw();
  
  leg3->AddEntry((TObject*)0, "ZPA vs. ZNA", "");
  leg3->Draw();
  
//_______________________ 

  //set energy ranges
  hNAvsNC->GetXaxis()->SetRangeUser(0, Et_ZN_nn);
  hNAvsNC->GetYaxis()->SetRangeUser(0, Et_ZN_nn);
  hPCvsNC->GetXaxis()->SetRangeUser(0, Et_ZN_np);
  hPCvsNC->GetYaxis()->SetRangeUser(0, Et_ZP);
  hPAvsNA->GetXaxis()->SetRangeUser(0, Et_ZN_np);
  hPAvsNA->GetYaxis()->SetRangeUser(0, Et_ZP);
  
//______________________________________________________________________

   pad->Update();
   pad->Print(PlotName);
  
}

