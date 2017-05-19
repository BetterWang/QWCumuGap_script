#include "../../style.h"
#include "published.h"

void initHist(TH2D* h);

void plotX(string fname1, string fname2, string fname3, string grs, vector<string> l, pair<double, double> xrange = make_pair<double, double>(1, 99), pair<double, double> yrange = make_pair<double, double>(0, 0.15))
{
	TFile * f1 = new TFile(fname1.c_str());
	TFile * f2 = new TFile(fname2.c_str());
	TFile * f3 = new TFile(fname3.c_str());

	TGraphErrors * gr1 = (TGraphErrors*) f1->Get(grs.c_str());
	TGraphErrors * gr2 = (TGraphErrors*) f2->Get(grs.c_str());
	TGraphErrors * gr3 = (TGraphErrors*) f3->Get(grs.c_str());

	if ( gr1 ) gr1->SetMarkerColor( kBlack );
	if ( gr2 ) gr2->SetMarkerColor( kRed );
	if ( gr3 ) gr3->SetMarkerColor( kBlue );
	if ( gr1 ) gr1->SetLineColor( kBlack );
	if ( gr2 ) gr2->SetLineColor( kRed );
	if ( gr3 ) gr3->SetLineColor( kBlue );

	TCanvas * cC = MakeCanvas("cC", "cC", 600, 500);
	TH2D * hframe = new TH2D("hframe", ";Centrality;v_{n}{m}", 1, xrange.first, xrange.second, 1, yrange.first, yrange.second);
	initHist(hframe);

	TLegend * legC = new TLegend(0.6, 0.25, 0.9, 0.4);
	legC->SetFillColor(kWhite);
	legC->SetTextFont(42);
	legC->SetTextSize(0.06);
	legC->SetBorderSize(0);


	hframe->Draw();
	gr1->Draw("psame");
	legC->AddEntry(gr1, l[0].c_str(), "p");
	gr2->Draw("psame");
	legC->AddEntry(gr2, l[1].c_str(), "p");

	if ( gr3 ) {
		gr3->Draw("psame");
		legC->AddEntry(gr3, l[2].c_str(), "p");
	}

	legC->Draw();

	TLatex latexB;
	latexB.SetTextFont(43);
	latexB.SetTextSize(24);
	latexB.SetTextAlign(13);
	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.30, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

}

void initHist(TH2D * h)
{
	h->GetXaxis()->CenterTitle();
	h->GetXaxis()->SetTitleOffset(1.3);

	h->GetYaxis()->CenterTitle();
	h->GetYaxis()->SetTitleOffset(1.3);

//	h->GetXaxis()->SetLabelFont(43);
//	h->GetXaxis()->SetLabelSize(20);
//	h->GetXaxis()->SetLabelOffset(0.02);
//	h->GetXaxis()->SetTitleFont(43);
//	h->GetXaxis()->SetTitleSize(22);
//	h->GetXaxis()->SetNdivisions(505);
//	h->GetXaxis()->SetTickLength(0.03);
//	h->GetXaxis()->SetTitleOffset(3);
//
//	h->GetYaxis()->SetLabelFont(43);
//	h->GetYaxis()->SetLabelSize(20);
//	h->GetYaxis()->SetLabelOffset(0.02);
//	h->GetYaxis()->SetTitleFont(43);
//	h->GetYaxis()->SetTitleSize(26);
//	h->GetYaxis()->CenterTitle();
//	h->GetYaxis()->SetNdivisions(505);
//	h->GetYaxis()->SetTickLength(0.03);
//	h->GetYaxis()->SetTitleOffset(1.5);
}
