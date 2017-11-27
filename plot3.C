#include "../../style.h"
#include "tools.h"


void plot3( TString spPb = "grV2_merged.root",
		TString sPbPb = "grV2PbPb_HFcut.root",
		TString sXeXe = "grV2XeXe_std.root",
		TString yLable = "v_{2}{4}",
		TString fsave = "c24_XeXe.pdf"
		)
{
	TFile * fpPb = new TFile(spPb.Data());
	TFile * fPbPb = new TFile(sPbPb.Data());
	TFile * fXeXe = new TFile(sXeXe.Data());

	VnGraph grpPb;
	VnGraph grPbPb;
	VnGraph grXeXe;

	int n = 2;
	if ( spPb[3] == '3' ) n = 3;

	getGraph(fpPb, grpPb, n);
	getGraph(fPbPb, grPbPb, n);
	getGraph(fXeXe, grXeXe, n);


	TCanvas * cC = MakeCanvas("cC", "cC", 500, 500);
	cC->SetTopMargin(0.06);
	//TLine *l0 = new TLine(0, 0, 399, 0);

	TH2D * hframe = new TH2D("hframe", "", 1, 0, 399, 1, 0.01, 0.14);
	InitHist(hframe, "N_{trk}^{offline}", yLable.Data());

	grpPb.grV4->SetMarkerColor(kBlack);
	grpPb.grV4->SetLineColor(kBlack);

	grPbPb.grV4->SetMarkerColor(kBlue);
	grPbPb.grV4->SetLineColor(kBlue);

	grXeXe.grV4->SetMarkerColor(kRed);
	grXeXe.grV4->SetLineColor(kRed);

	hframe->Draw();
	grpPb.grV4->Draw("p");
	grPbPb.grV4->Draw("p");
	grXeXe.grV4->Draw("p");

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.20, 0.91, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV42 = new TLegend(0.20, 0.65, 0.65, 0.85);
	legV42->SetFillColor(kWhite);
	legV42->SetTextFont(42);
	legV42->SetTextSize(0.05);
	legV42->SetBorderSize(0);

	legV42->AddEntry(grXeXe.grV4, "XeXe 5.44 TeV", "p");
	legV42->AddEntry(grPbPb.grV4, "PbPb 5.02 TeV", "p");
	legV42->AddEntry(grpPb.grV4, "pPb 8.16 TeV", "p");

	legV42->Draw();

	cC->SaveAs(fsave.Data());
}
