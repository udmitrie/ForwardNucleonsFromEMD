	const char* FileName = "results/AnalysisResults_full.root";
	
	TFile* File=new TFile(FileName);
	
	const char* NAvsNC = "fCorrNAvsNC";
	const char* PCvsNC = "fCorrPCvsNC";								//isZPC = true
	const char* PAvsNA = "fCorrPAvsNA";								//isZPA
	TH2F* hNAvsNC = (TH2F*) File->Get(NAvsNC); 
	TH2F* hPCvsNC = (TH2F*) File->Get(PCvsNC); 
	TH2F* hPAvsNA = (TH2F*) File->Get(PAvsNA); 
	
	const char* ZNC = "fZNCSpectrum";								//isZNC
	const char* ZNA = "fZNASpectrum";								//isZNA
	const char* ZPC = "fZPCSpectrum";								//isZPC
	const char* ZPA = "fZPASpectrum";									//isZPA
	TH1D* hZNC = (TH1D*) File->Get(ZNC);
	TH1D* hZNA = (TH1D*) File->Get(ZNA);
	TH1D* hZPC = (TH1D*) File->Get(ZPC);
	TH1D* hZPA = (TH1D*) File->Get(ZPA);
	
	const char* ZNC_sm = "fZNCSpectrum_singleminmutualEMD";			//isZNC && !isZNA
	const char* ZNA_sm = "fZNASpectrum_singleminmutualEMD";			//isZNA && !isZNC
	TH1D* hZNC_sm = (TH1D*) File->Get(ZNC_sm);
	TH1D* hZNA_sm = (TH1D*) File->Get(ZNA_sm);
	
	//EM evnts: !isZEM1 && !isZEM2
	
	const char* NAvsNC_em = "fCorrNAvsNCem";						
	const char* PCvsNC_em = "fCorrPCvsNCem";						//isZNC  && isZPC
	const char* PAvsNA_em = "fCorrPAvsNAem";						//isZNA  && isZPA
	TH2F* hNAvsNC_em = (TH2F*) File->Get(NAvsNC_em); 
	TH2F* hPCvsNC_em = (TH2F*) File->Get(PCvsNC_em); 
	TH2F* hPAvsNA_em = (TH2F*) File->Get(PAvsNA_em);
	
	
	
	const char* PCvsNC_em_single = "fCorrNCvsPCem_only1side";		//isZPC
	const char* PAvsNA_em_single = "fCorrNAvsPAem_only1side";		//isZPA

	const char* ZNC_em = "fZNCSpectrumEM";							//isZNC
	const char* ZNA_em = "fZNASpectrumEM";							//isZNA
	const char* ZPC_em = "fZPCSpectrumEM";							//isZPC
	const char* ZPA_em = "fZPASpectrumEM";							//isZPA
	TH1D* hZNC_em = (TH1D*) File->Get(ZNC_em);
	TH1D* hZNA_em = (TH1D*) File->Get(ZNA_em);
	TH1D* hZPC_em = (TH1D*) File->Get(ZPC_em);
	TH1D* hZPA_em = (TH1D*) File->Get(ZPA_em);


	const char* ZPC_1n = "fZPCSpectrumEM_1n";						//isZPC && isZNC
	const char* ZPA_1n = "fZPASpectrumEM_1n";						//isZPA && isZNA
	TH1D* hZPC_1n = (TH1D*) File->Get(ZPC_1n);
	TH1D* hZPA_1n = (TH1D*) File->Get(ZPA_1n);

	const char* ZNC_0p = "fZNCSpectrumEM_0p";						//isZNC && !isZPC
	const char* ZNA_0p = "fZNASpectrumEM_0p";						//isZNA && !isZPA
	TH1D* hZNC_0p = (TH1D*) File->Get(ZNC_0p);
	TH1D* hZNA_0p = (TH1D*) File->Get(ZNA_0p);
	
	const char* ZPC_3n = "fZPCSpectrumEM_3n";						//isZPC && zncEnergy<E(3n)
	const char* ZPA_3n = "fZPASpectrumEM_3n";						//isZPA && znaEnergy<E(3n)
	TH1D* hZPC_3n = (TH1D*) File->Get(ZPC_3n);
	TH1D* hZPA_3n = (TH1D*) File->Get(ZPA_3n);
	
	
	//Hadronic events: isZEM1 || isZEM2
	
	const char* NAvsNC_h = "fCorrNAvsNCh";
	const char* PCvsNC_h = "fCorrPCvsNCh";							//isZPC
	const char* PAvsNA_h = "fCorrPAvsNAh";							//isZPA
	TH2F* hNAvsNC_h = (TH2F*) File->Get(NAvsNC_h); 
	TH2F* hPCvsNC_h = (TH2F*) File->Get(PCvsNC_h); 
	TH2F* hPAvsNA_h = (TH2F*) File->Get(PAvsNA_h);

	const char* NAvsEM = "fCorrZNAvsZEM";
	const char* PAvsEM = "fCorrZPAvsZEM";
	TH2F* hNAvsEM = (TH2F*) File->Get(NAvsEM); 
	TH2F* hPAvsEM = (TH2F*) File->Get(PAvsEM); 

	
	
		
		
		
		
		
		
		
	
	
