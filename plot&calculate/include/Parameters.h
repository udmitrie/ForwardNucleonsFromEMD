
#include <includes/Histograms_names.h>

//Pb_Pb parameters
	
	const double inf=RooNumber::infinity(); 
	
	const float E0=2510;		//beam energy
	Float_t sED = 414.3;		//EMD cross-section from VdM scan
	
	//max energies for histograms
	Float_t maxE_ZN = 240000; 
	Float_t maxE_ZP = 80000;
	Float_t maxE_ZEM = 2000;
	
	//number of electromagnetic events that corresponds to sED
	const double totED = hNAvsNC_em->GetEntries();


	void set_plot_style()
{
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}
