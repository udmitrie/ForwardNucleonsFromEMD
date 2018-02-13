
		Int_t Emin, Emax, Et;
		Double_t E0_real, Sigma0; //mean and width of peak 
		
		Float_t en, ev;

		Double_t con, mean, sigm;  
        
		Float_t nEv;			//number of events
		Float_t nEr_fit;		//fit error 
		Float_t nEr_syst;		//systematic error	
		Float_t sg;			//cross-section
		Float_t sgEr_fit;		//fit error 
		Float_t sgEr_syst; 		//systematic error
		Float_t sgEr;			//total error
		Int_t npeaks, nfit; //number of peaks for fit, number of peaks to calculate cross-sections


        Float_t minX1 = 0;
		Float_t minX2 = 0;
		
		TString condition; //cuts
