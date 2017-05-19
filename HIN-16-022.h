TGraphErrors * grHIN16022pPbV2 = 0;
TGraphErrors * grHIN16022pPbV3 = 0;
TGraphErrors * grHIN16022pPbV4 = 0;

TGraphErrors * grHIN16022PbPbV2 = 0;
TGraphErrors * grHIN16022PbPbV3 = 0;
TGraphErrors * grHIN16022PbPbV4 = 0;

void HIN_16_022()
{
	TFile * fpPb = new TFile("pPbPbp8TeV_v2v3v4_vsN_dz01_NoHighPU1.root");
	TFile * fPbPb = new TFile("PbPb5TeV_v2v3v4_vsN_N020sub.root");

	grHIN16022pPbV2 = (TGraphErrors*) fpPb->Get("hadronv2sub");
	grHIN16022pPbV3 = (TGraphErrors*) fpPb->Get("hadronv3sub");
	grHIN16022pPbV4 = (TGraphErrors*) fpPb->Get("hadronv4sub");

	grHIN16022PbPbV2 = (TGraphErrors*) fPbPb->Get("hadronv2sub");
	grHIN16022PbPbV3 = (TGraphErrors*) fPbPb->Get("hadronv3sub");
	grHIN16022PbPbV4 = (TGraphErrors*) fPbPb->Get("hadronv4sub");

	grHIN16022pPbV2->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV3->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV4->SetMarkerStyle(kOpenCircle);

	grHIN16022PbPbV2->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV3->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV4->SetMarkerStyle(kOpenCircle);

	grHIN16022pPbV2->SetMarkerColor(kRed);
	grHIN16022pPbV3->SetMarkerColor(kRed);
	grHIN16022pPbV4->SetMarkerColor(kRed);

	grHIN16022PbPbV2->SetMarkerColor(kRed);
	grHIN16022PbPbV3->SetMarkerColor(kRed);
	grHIN16022PbPbV4->SetMarkerColor(kRed);

	grHIN16022pPbV2->SetLineColor(kRed);
	grHIN16022pPbV3->SetLineColor(kRed);
	grHIN16022pPbV4->SetLineColor(kRed);

	grHIN16022PbPbV2->SetLineColor(kRed);
	grHIN16022PbPbV3->SetLineColor(kRed);
	grHIN16022PbPbV4->SetLineColor(kRed);

	fpPb->Close();
	fPbPb->Close();
}
