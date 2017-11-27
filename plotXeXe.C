#include "../../style.h"

void plotXeXe(TString fname = "txt/XeXe_eff_Cent/outGraph.root")
{
	TFile * f = new TFile(fname.Data());

	TGraphErrors * grV22 = (TGraphErrors*) f->Get("grV22");
	TGraphErrors * grV42 = (TGraphErrors*) f->Get("grV42");
	TGraphErrors * grV62 = (TGraphErrors*) f->Get("grV62");
	TGraphErrors * grV82 = (TGraphErrors*) f->Get("grV82");

	TCanvas * cC = MakeCanvas("cC", "cC", 500, 500);

	TH2D * hframe = new TH2D("hframe", "", 1, 0, 99, 1, 0.01, 0.14);
	InitHist(hframe, "Centrality (%)", "v_{2}");

	while ( grV82->GetX()[0] < 40 ) grV82->RemovePoint(0);
	while ( grV62->GetX()[0] < 30 ) grV62->RemovePoint(0);
	while ( grV42->GetX()[0] < 20 ) grV42->RemovePoint(0);

	hframe->Draw();

//	grV22->Draw("psame");
	grV42->Draw("psame");
	grV62->Draw("psame");
	grV82->Draw("psame");

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS XeXe 5.44 TeV Preliminary}");
	latexS.DrawLatexNDC(0.20, 0.91, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV42 = new TLegend(0.20, 0.65, 0.65, 0.85);
	legV42->SetFillColor(kWhite);
	legV42->SetTextFont(42);
	legV42->SetTextSize(0.05);
	legV42->SetBorderSize(0);

	legV42->AddEntry(grV42, "v_{2}{4}", "p");
	legV42->AddEntry(grV62, "v_{2}{6}", "p");
	legV42->AddEntry(grV82, "v_{2}{8}", "p");

	legV42->Draw();

	cC->SaveAs("XeXe_v2.pdf");
}
