TGraphErrors * grHIN14006pPbV26 = 0;
TGraphErrors * grHIN14006pPbV28 = 0;

TGraphErrors * grHIN14006PbPbV26 = 0;
TGraphErrors * grHIN14006PbPbV28 = 0;

void HIN_14_006()
{
// PbPb v26
	double PbPb_noff6[] = {
		334.3,
		309.4,
		289.4,
		269.4,
		249.4,
		229.4,
		201.6,
		166.5,
		134.1,
		109.3,
		89.2 ,
		69.12,
		54.38
	};

	double PbPb_v26[] = {
		0.08249,
		0.08148,
		0.08098,
		0.07946,
		0.0788 ,
		0.07748,
		0.07574,
		0.07294,
		0.06989,
		0.06541,
		0.06483,
		0.05985,
		0.06082
	};

	double PbPb_v26e[] = {
		0.00031,
		0.00029,
		0.00035,
		0.00036,
		0.0003 ,
		0.00035,
		0.00036,
		0.00042,
		0.00046,
		0.00086,
		0.00112,
		0.00226,
		0.00427
	};
	double PbPb_v26s[] = {
		0.00152,
		0.00151,
		0.00160,
		0.00149,
		0.0015 ,
		0.00141,
		0.00145,
		0.00136,
		0.00127,
		0.00160,
		0.00096,
		0.00150,
		0.00195
	};

// PbPb v28
	double PbPb_noff8[] = {
		334.3,
		309.4,
		289.4,
		269.4,
		249.4,
		229.4,
		201.6,
		166.5,
		134.1,
		109.3,
		89.2 ,
		69.1
	};
	double PbPb_v28[] = {
		0.08233,
		0.08132,
		0.08064,
		0.07918,
		0.07842,
		0.07721,
		0.0755 ,
		0.0725 ,
		0.06946,
		0.06543,
		0.06504,
		0.0638
	};
	double PbPb_v28e[] = {
		0.00035,
		0.00034,
		0.00044,
		0.00043,
		0.00041,
		0.00042,
		0.0005 ,
		0.0006 ,
		0.00064,
		0.00131,
		0.00159,
		0.0026
	};
	double PbPb_v28s[] = {
		0.00151,
		0.00151,
		0.00160,
		0.00147,
		0.00144,
		0.00141,
		0.0014 ,
		0.0014 ,
		0.00126,
		0.00154,
		0.00093,
		0.0037
	};
// pPb v26

	double pPb_noff6[] = {
		270.5,
		247.2,
		227.5,
		196.7,
		162.1,
		131.3,
		108.2
	};

	double pPb_v26[] = {
		0.0485 ,
		0.04013,
		0.04462,
		0.04495,
		0.04491,
		0.04695,
		0.04862 
	};

	double pPb_v26e[] = {
		0.0040 ,
		0.00308,
		0.00096,
		0.00059,
		0.00068,
		0.00115,
		0.00403
	};

	double pPb_v26s[] = {
		0.0024 ,
		0.00201,
		0.00223,
		0.00225,
		0.00225,
		0.00235,
		0.00243
	};
// pPb v28

	double pPb_noff8[] = {
		196.7,
		162.1,
		131.3,
		108.2
	};
	double pPb_v28[] = {
		0.04282,
		0.04504,
		0.04619,
		0.05654
	};
	double pPb_v28e[] = {
		0.00227,
		0.00203,
		0.00227,
		0.00248
	};
	double pPb_v28s[] = {
		0.00257,
		0.00270,
		0.00277,
		0.00339
	};

	grHIN14006PbPbV26 = new TGraphErrors(13, PbPb_noff6, PbPb_v26, 0, PbPb_v26e);
	grHIN14006PbPbV28 = new TGraphErrors(12, PbPb_noff8, PbPb_v28, 0, PbPb_v28e);

	grHIN14006pPbV26 = new TGraphErrors(7, pPb_noff6, pPb_v26, 0, pPb_v26e);
	grHIN14006pPbV28 = new TGraphErrors(4, pPb_noff8, pPb_v28, 0, pPb_v28e);


	grHIN14006PbPbV26->SetMarkerStyle(kOpenCross);
	grHIN14006PbPbV28->SetMarkerStyle(kOpenDiamond);
	grHIN14006pPbV26->SetMarkerStyle(kOpenCross);
	grHIN14006pPbV28->SetMarkerStyle(kOpenDiamond);

	grHIN14006PbPbV26->SetMarkerColor(kBlue);
	grHIN14006PbPbV28->SetMarkerColor(kRed);
	grHIN14006pPbV26->SetMarkerColor(kBlue);
	grHIN14006pPbV28->SetMarkerColor(kRed);

	grHIN14006PbPbV26->SetLineColor(kBlue);
	grHIN14006PbPbV28->SetLineColor(kRed);
	grHIN14006pPbV26->SetLineColor(kBlue);
	grHIN14006pPbV28->SetLineColor(kRed);
}
