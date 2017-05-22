#include "../../style.h"
#include "HIN-16-022.h"
#include "HIN-14-006.h"

typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
	TGraphErrors * grC6;
	TGraphErrors * grV6;
	TGraphErrors * grC8;
	TGraphErrors * grV8;
} VnGraph;

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grC%in", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grV%in", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC%i4", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV%i4", n));

	gr.grC6 = (TGraphErrors*) f->Get(Form("grC%i6", n));
	gr.grV6 = (TGraphErrors*) f->Get(Form("grV%i6", n));

	gr.grC8 = (TGraphErrors*) f->Get(Form("grC%i8", n));
	gr.grV8 = (TGraphErrors*) f->Get(Form("grV%i8", n));
}


void plotC(TString s2pPb = "grV2_merged.root",
		TString s3pPb = "grV3_merged.root",
		TString s2PbPb = "grV2PbPb_sysTight2.root",
		TString s3PbPb = "grV3PbPb_sysTight2.root",
		TString s2pp = "grV2_pp13.root",
		TString s3pp = "grV3_pp13.root")
{
	TFile *f2pPb = new TFile(s2pPb.Data());
	TFile *f3pPb = new TFile(s3pPb.Data());
	TFile *f2PbPb = new TFile(s2PbPb.Data());
	TFile *f3PbPb = new TFile(s3PbPb.Data());
	TFile *f2pp = new TFile(s2pp.Data());
	TFile *f3pp = new TFile(s3pp.Data());

	HIN_16_022();
	HIN_14_006();

	VnGraph grPA2;
	VnGraph grPA3;
	VnGraph grAA2;
	VnGraph grAA3;
	VnGraph grPP2;
	VnGraph grPP3;

	getGraph( f2pPb, grPA2, 2 );
	getGraph( f3pPb, grPA3, 3 );
	getGraph( f2PbPb, grAA2, 2 );
	getGraph( f3PbPb, grAA3, 3 );
	getGraph( f2pp, grPP2, 2 );
	getGraph( f3pp, grPP3, 3 );


	grAA2.grC4->SetMarkerStyle(kFullSquare);
	grAA3.grC4->SetMarkerStyle(kFullSquare);

	TLatex latexB;
	latexB.SetTextFont(43);
	latexB.SetTextSize(24);
	latexB.SetTextAlign(13);
	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	TCanvas * cC = MakeCanvas("cC", "cC", 900, 500);
//	makeMultiPanelCanvas(cC, 2, 1);
	TLine *l0 = new TLine(0, 0, 399, 0);

	cC->Divide(2, 1);
	TH2D * hframeC2 = new TH2D("hframeC2", "", 1, 0, 399, 1, -0.00009, 0.00005);
	InitHist(hframeC2, "N_{trk}^{offline}", "c_{2}{4}");

	TH2D * hframeC3 = new TH2D("hframeC3", "", 1, 0, 399, 1, -0.0000005, 0.000001);
	InitHist(hframeC3, "N_{trk}^{offline}", "c_{3}{4}");

	auto p = cC->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2->Draw();
	l0->Draw();
	grPA2.grC4->Draw("Psame");
	grAA2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.30, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	p = cC->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3->Draw();
	l0->Draw();
	grPA3.grC4->Draw("Psame");
	grAA3.grC4->Draw("Psame");

	TLegend * legC = new TLegend(0.4, 0.75, 0.85, 0.9);
	legC->SetFillColor(kWhite);
	legC->SetTextFont(42);
	legC->SetTextSize(0.06);
	legC->SetBorderSize(0);

	legC->AddEntry(grPA3.grC4, "pPb 8.16 TeV", "p");
	legC->AddEntry(grAA3.grC4, "PbPb 5.02 TeV", "p");
	legC->Draw();

	///////////////////////////
	TCanvas * cCgap = MakeCanvas("cCgap", "cCgap", 1500, 500);
//	makeMultiPanelCanvas(cC, 2, 1);

	cCgap->Divide(3, 1);


	TH2D * hframeC2pp = new TH2D("hframeC2pp", "", 1, 0, 399, 1, -0.000019, 0.00001);
	InitHist(hframeC2pp, "N_{trk}^{offline}", "c_{2}{4}");
	p = cCgap->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2pp->Draw();
	l0->Draw();
	grPP2.grCn->Draw("Psame");
	grPP2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS} Preliminary");
	latexS.DrawLatexNDC(0.30, 0.85, "pp #sqrt{s} = 13 TeV");

	p = cCgap->cd(2);
	TH2D * hframeC2pA = new TH2D("hframeC2pA", "", 1, 0, 399, 1, -0.000019, 0.00002);
	InitHist(hframeC2pA, "N_{trk}^{offline}", "c_{2}{4}");
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2pA->Draw();
	l0->Draw();
	grPA2.grCn->Draw("Psame");
	grPA2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	latexS.DrawLatexNDC(0.30, 0.85, "pPb #sqrt{s_{NN}} = 8.16 TeV");

	p = cCgap->cd(3);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2->Draw();
	l0->Draw();
	grAA2.grCn->Draw("Psame");
	grAA2.grC4->Draw("Psame");
	latexS.DrawLatexNDC(0.30, 0.85, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * legCgap = new TLegend(0.2, 0.25, 0.45, 0.4);
	legCgap->SetFillColor(kWhite);
	legCgap->SetTextFont(42);
	legCgap->SetTextSize(0.06);
	legCgap->SetBorderSize(0);

	legCgap->AddEntry(grPP2.grCn, "c_{2}{4} 3-sub", "p");
	legCgap->AddEntry(grAA2.grC4, "c_{2}{4}", "p");
	legCgap->Draw();

	///////////////////////////

	TCanvas * cCgap3 = MakeCanvas("cCgap3", "cCgap3", 1500, 500);
//	makeMultiPanelCanvas(cC, 2, 1);

	cCgap3->Divide(3, 1);


	TH2D * hframeC3pp = new TH2D("hframeC3pp", "", 1, 0, 399, 1, -0.00001, 0.00001);
	InitHist(hframeC3pp, "N_{trk}^{offline}", "c_{3}{4}");
	p = cCgap3->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3pp->Draw();
	l0->Draw();
	grPP3.grCn->Draw("Psame");
	grPP3.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS} Preliminary");
	latexS.DrawLatexNDC(0.30, 0.85, "pp #sqrt{s} = 13 TeV");

	p = cCgap3->cd(2);
	TH2D * hframeC3pA = new TH2D("hframeC3pA", "", 1, 0, 399, 1, -0.0000019, 0.000005);
	InitHist(hframeC3pA, "N_{trk}^{offline}", "c_{3}{4}");
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3pA->Draw();
	l0->Draw();
	grPA3.grCn->Draw("Psame");
	grPA3.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	latexS.DrawLatexNDC(0.30, 0.85, "pPb #sqrt{s_{NN}} = 8.16 TeV");

	p = cCgap3->cd(3);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3->Draw();
	l0->Draw();
	grAA3.grCn->Draw("Psame");
	grAA3.grC4->Draw("Psame");
	latexS.DrawLatexNDC(0.30, 0.85, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * legCgap3 = new TLegend(0.2, 0.25, 0.45, 0.4);
	legCgap3->SetFillColor(kWhite);
	legCgap3->SetTextFont(42);
	legCgap3->SetTextSize(0.06);
	legCgap3->SetBorderSize(0);

	legCgap3->AddEntry(grPP2.grCn, "c_{3}{4} 3-sub", "p");
	legCgap3->AddEntry(grAA2.grC4, "c_{3}{4}", "p");
	legCgap3->Draw();

	////gap///////////////////////////
	TCanvas * cV = MakeCanvas("cV", "cV", 900, 500);
//	makeMultiPanelCanvas(cC, 2, 1);
	cV->Divide(2, 1);

	TH2D * hframeV2 = new TH2D("hframeV2", "", 1, 0, 399, 1, 0.01, 0.14);
	InitHist(hframeV2, "N_{trk}^{offline}", "v_{n}{m}");

	grPA3.grV4->SetMarkerStyle(kOpenCircle);
	grAA3.grV4->SetMarkerStyle(kOpenCircle);

	p = cV->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grPA2.grV4->Draw("Psame");
	grPA3.grV4->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV = new TLegend(0.4, 0.55, 0.85, 0.7);
	legV->SetFillColor(kWhite);
	legV->SetTextFont(42);
	legV->SetTextSize(0.06);
	legV->SetBorderSize(0);

	legV->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV->AddEntry(grAA3.grV4, "v_{3}{4}", "p");
	legV->Draw();

	p = cV->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grAA2.grV4->Draw("Psame");
	grAA3.grV4->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	////////////////////////////////////
	TCanvas * cV2 = MakeCanvas("cV2", "cV2", 900, 500);
	cV2->Divide(2, 1);



	p = cV2->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grPA2.grV4->Draw("Psame");
	grPA2.grV6->Draw("Psame");
	grPA2.grV8->Draw("Psame");
	grHIN16022pPbV2->Draw("Psame");
	grHIN14006pPbV26->Draw("Psame");
	grHIN14006pPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV2 = new TLegend(0.4, 0.55, 0.85, 0.8);
	legV2->SetFillColor(kWhite);
	legV2->SetTextFont(42);
	legV2->SetTextSize(0.06);
	legV2->SetBorderSize(0);

	legV2->AddEntry(grHIN16022PbPbV2, "v_{2}{2, |#Delta#eta|>2}", "p");
	legV2->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV2->AddEntry(grPA2.grV6, "v_{2}{6}", "p");
	legV2->AddEntry(grPA2.grV8, "v_{2}{8}", "p");
	legV2->Draw();

	p = cV2->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grAA2.grV4->Draw("Psame");
	grAA2.grV6->Draw("Psame");
	grAA2.grV8->Draw("Psame");
	grHIN16022PbPbV2->Draw("Psame");
	grHIN14006PbPbV26->Draw("Psame");
	grHIN14006PbPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	///////// V3
	TCanvas * cV3 = MakeCanvas("cV3", "cV3", 900, 500);
	cV3->Divide(2, 1);

	grPA3.grV4->SetMarkerStyle(kOpenSquare);
	grAA3.grV4->SetMarkerStyle(kOpenSquare);

	p = cV3->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grPA3.grV4->Draw("Psame");
//	grPA3.grV6->Draw("Psame");
//	grPA3.grV8->Draw("Psame");
	grHIN16022pPbV3->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV3 = new TLegend(0.4, 0.55, 0.85, 0.8);
	legV3->SetFillColor(kWhite);
	legV3->SetTextFont(42);
	legV3->SetTextSize(0.06);
	legV3->SetBorderSize(0);

	legV3->AddEntry(grHIN16022PbPbV2, "v_{3}{2, |#Delta#eta|>2}", "p");
	legV3->AddEntry(grPA3.grV4, "v_{3}{4}", "p");
//	legV3->AddEntry(grPA3.grV6, "v_{3}{6}", "p");
//	legV3->AddEntry(grPA3.grV8, "v_{3}{8}", "p");
	legV3->Draw();

	p = cV3->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeV2->Draw();
	grAA3.grV4->Draw("Psame");
//	grAA3.grV6->Draw("Psame");
//	grAA3.grV8->Draw("Psame");
	grHIN16022PbPbV3->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	//
	/////
	cC->SaveAs("c4.pdf");
	cCgap->SaveAs("c24gap.pdf");
	cCgap3->SaveAs("c34gap.pdf");
	cV->SaveAs("v23.pdf");
	cV2->SaveAs("v2.pdf");
	cV3->SaveAs("v3.pdf");
	/////

}
