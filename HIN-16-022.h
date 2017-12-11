TGraphErrors * grHIN16022pPbV2 = 0;
TGraphErrors * grHIN16022pPbV3 = 0;
TGraphErrors * grHIN16022pPbV4 = 0;

TGraphErrors * grHIN16022pPbV2sub = 0;
TGraphErrors * grHIN16022pPbV3sub = 0;
TGraphErrors * grHIN16022pPbV4sub = 0;

TGraphErrors * grHIN16022pPbV2int = 0;
TGraphErrors * grHIN16022pPbV3int = 0;
TGraphErrors * grHIN16022pPbV4int = 0;

TGraphErrors * grHIN16022pPbV2intsub = 0;
TGraphErrors * grHIN16022pPbV3intsub = 0;
TGraphErrors * grHIN16022pPbV4intsub = 0;

TF1 * fHIN16022pPbV2 = 0;
TF1 * fHIN16022pPbV3 = 0;
TF1 * fHIN16022pPbV4 = 0;

TF1 * fHIN16022pPbV2sub = 0;
TF1 * fHIN16022pPbV3sub = 0;
TF1 * fHIN16022pPbV4sub = 0;

TGraphErrors * grHIN16022PbPbV2 = 0;
TGraphErrors * grHIN16022PbPbV3 = 0;
TGraphErrors * grHIN16022PbPbV4 = 0;

TGraphErrors * grHIN16022PbPbV2sub = 0;
TGraphErrors * grHIN16022PbPbV3sub = 0;
TGraphErrors * grHIN16022PbPbV4sub = 0;

TGraphErrors * grHIN16022PbPbV2int = 0;
TGraphErrors * grHIN16022PbPbV3int = 0;
TGraphErrors * grHIN16022PbPbV4int = 0;

TGraphErrors * grHIN16022PbPbV2intsub = 0;
TGraphErrors * grHIN16022PbPbV3intsub = 0;
TGraphErrors * grHIN16022PbPbV4intsub = 0;

TF1 * fHIN16022PbPbV2 = 0;
TF1 * fHIN16022PbPbV3 = 0;
TF1 * fHIN16022PbPbV4 = 0;

TF1 * fHIN16022PbPbV2sub = 0;
TF1 * fHIN16022PbPbV3sub = 0;
TF1 * fHIN16022PbPbV4sub = 0;


void trimNaN(TGraphErrors * gr)
{
	for ( int i = 0; i < gr->GetN(); i++ ) {
		if ( gr->GetY()[i] != gr->GetY()[i] or gr->GetY()[i]== 0. or gr->GetX()[i] > 399. ) {
			gr->RemovePoint(i);
			i--;
		}
	}
}

void HIN_16_022()
{
	TFile * fpPb = new TFile("pPbPbp8TeV_v2v3v4_vsN_dz01_NoHighPU1.root");
	TFile * fPbPb = new TFile("PbPb5TeV_v2v3v4_vsN_N020sub.root");

	grHIN16022pPbV2 = (TGraphErrors*) fpPb->Get("hadronv2");
	grHIN16022pPbV3 = (TGraphErrors*) fpPb->Get("hadronv3");
	grHIN16022pPbV4 = (TGraphErrors*) fpPb->Get("hadronv4");

	grHIN16022pPbV2sub = (TGraphErrors*) fpPb->Get("hadronv2sub");
	grHIN16022pPbV3sub = (TGraphErrors*) fpPb->Get("hadronv3sub");
	grHIN16022pPbV4sub = (TGraphErrors*) fpPb->Get("hadronv4sub");

	grHIN16022PbPbV2 = (TGraphErrors*) fPbPb->Get("hadronv2");
	grHIN16022PbPbV3 = (TGraphErrors*) fPbPb->Get("hadronv3");
	grHIN16022PbPbV4 = (TGraphErrors*) fPbPb->Get("hadronv4");

	grHIN16022PbPbV2sub = (TGraphErrors*) fPbPb->Get("hadronv2sub");
	grHIN16022PbPbV3sub = (TGraphErrors*) fPbPb->Get("hadronv3sub");
	grHIN16022PbPbV4sub = (TGraphErrors*) fPbPb->Get("hadronv4sub");

	trimNaN(grHIN16022pPbV2);
	trimNaN(grHIN16022pPbV3);
	trimNaN(grHIN16022pPbV4);

	trimNaN(grHIN16022pPbV2sub);
	trimNaN(grHIN16022pPbV3sub);
	trimNaN(grHIN16022pPbV4sub);

	trimNaN(grHIN16022PbPbV2);
	trimNaN(grHIN16022PbPbV3);
	trimNaN(grHIN16022PbPbV4);

	trimNaN(grHIN16022PbPbV2sub);
	trimNaN(grHIN16022PbPbV3sub);
	trimNaN(grHIN16022PbPbV4sub);

	grHIN16022pPbV2->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV3->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV4->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV2sub->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV3sub->SetMarkerStyle(kOpenCircle);
	grHIN16022pPbV4sub->SetMarkerStyle(kOpenCircle);

	grHIN16022PbPbV2->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV3->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV4->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV2sub->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV3sub->SetMarkerStyle(kOpenCircle);
	grHIN16022PbPbV4sub->SetMarkerStyle(kOpenCircle);

	grHIN16022pPbV2->SetMarkerColor(kRed);
	grHIN16022pPbV3->SetMarkerColor(kRed);
	grHIN16022pPbV4->SetMarkerColor(kRed);
	grHIN16022pPbV2sub->SetMarkerColor(kRed);
	grHIN16022pPbV3sub->SetMarkerColor(kRed);
	grHIN16022pPbV4sub->SetMarkerColor(kRed);

	grHIN16022PbPbV2->SetMarkerColor(kRed);
	grHIN16022PbPbV3->SetMarkerColor(kRed);
	grHIN16022PbPbV4->SetMarkerColor(kRed);
	grHIN16022PbPbV2sub->SetMarkerColor(kRed);
	grHIN16022PbPbV3sub->SetMarkerColor(kRed);
	grHIN16022PbPbV4sub->SetMarkerColor(kRed);

	grHIN16022pPbV2->SetLineColor(kRed);
	grHIN16022pPbV3->SetLineColor(kRed);
	grHIN16022pPbV4->SetLineColor(kRed);
	grHIN16022pPbV2sub->SetLineColor(kRed);
	grHIN16022pPbV3sub->SetLineColor(kRed);
	grHIN16022pPbV4sub->SetLineColor(kRed);

	grHIN16022PbPbV2->SetLineColor(kRed);
	grHIN16022PbPbV3->SetLineColor(kRed);
	grHIN16022PbPbV4->SetLineColor(kRed);
	grHIN16022PbPbV2sub->SetLineColor(kRed);
	grHIN16022PbPbV3sub->SetLineColor(kRed);
	grHIN16022PbPbV4sub->SetLineColor(kRed);

	grHIN16022pPbV2int = (TGraphErrors*)grHIN16022pPbV2->Clone();
	grHIN16022pPbV3int = (TGraphErrors*)grHIN16022pPbV3->Clone();
	grHIN16022pPbV4int = (TGraphErrors*)grHIN16022pPbV4->Clone();
	grHIN16022pPbV2intsub = (TGraphErrors*)grHIN16022pPbV2sub->Clone();
	grHIN16022pPbV3intsub = (TGraphErrors*)grHIN16022pPbV3sub->Clone();
	grHIN16022pPbV4intsub = (TGraphErrors*)grHIN16022pPbV4sub->Clone();

	grHIN16022PbPbV2int = (TGraphErrors*)grHIN16022PbPbV2->Clone();
	grHIN16022PbPbV3int = (TGraphErrors*)grHIN16022PbPbV3->Clone();
	grHIN16022PbPbV4int = (TGraphErrors*)grHIN16022PbPbV4->Clone();
	grHIN16022PbPbV2intsub = (TGraphErrors*)grHIN16022PbPbV2sub->Clone();
	grHIN16022PbPbV3intsub = (TGraphErrors*)grHIN16022PbPbV3sub->Clone();
	grHIN16022PbPbV4intsub = (TGraphErrors*)grHIN16022PbPbV4sub->Clone();

	fpPb->Close();
	fPbPb->Close();

	fHIN16022pPbV2 = new TF1("fHIN16022pPbV2", "pol6", 30, 399);
	fHIN16022pPbV3 = new TF1("fHIN16022pPbV3", "pol6", 50, 399);
	fHIN16022pPbV2sub = new TF1("fHIN16022pPbV2sub", "pol6", 30, 399);
	fHIN16022pPbV3sub = new TF1("fHIN16022pPbV3sub", "pol6", 50, 399);

	grHIN16022pPbV2->Fit(fHIN16022pPbV2, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022pPbV2int);
	grHIN16022pPbV3->Fit(fHIN16022pPbV3, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022pPbV3int);

	grHIN16022pPbV2sub->Fit(fHIN16022pPbV2sub, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022pPbV2intsub);
	grHIN16022pPbV3sub->Fit(fHIN16022pPbV3sub, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022pPbV3intsub);

	fHIN16022PbPbV2 = new TF1("fHIN16022PbPbV2", "pol6", 30, 399);
	fHIN16022PbPbV3 = new TF1("fHIN16022PbPbV3", "pol6", 50, 399);
	fHIN16022PbPbV2sub = new TF1("fHIN16022PbPbV2sub", "pol6", 30, 399);
	fHIN16022PbPbV3sub = new TF1("fHIN16022PbPbV3sub", "pol6", 50, 399);

	grHIN16022PbPbV2->Fit(fHIN16022PbPbV2, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022PbPbV2int);
	grHIN16022PbPbV3->Fit(fHIN16022PbPbV3, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022PbPbV3int);

	grHIN16022PbPbV2sub->Fit(fHIN16022PbPbV2sub, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022PbPbV2intsub);
	grHIN16022PbPbV3sub->Fit(fHIN16022PbPbV3sub, "QRN");
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(grHIN16022PbPbV3intsub);
}
