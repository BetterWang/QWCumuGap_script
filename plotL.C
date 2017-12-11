#include "HIN-16-022.h"
#include "published.h"
#include "tools.h"
#include "../../style.h"

//typedef struct
//{
//	TGraphErrors * grCn;
//	TGraphErrors * grVn;
//	TGraphErrors * grC4;
//	TGraphErrors * grV4;
//	TGraphErrors * grC6;
//	TGraphErrors * grV6;
//	TGraphErrors * grC8;
//	TGraphErrors * grV8;
//} VnGraph;

//void getGraph(TFile * f, VnGraph &gr, int n)
//{
//	gr.grCn = (TGraphErrors*) f->Get(Form("grC%in", n));
//	gr.grVn = (TGraphErrors*) f->Get(Form("grV%in", n));
//
//	gr.grC4 = (TGraphErrors*) f->Get(Form("grC%i4", n));
//	gr.grV4 = (TGraphErrors*) f->Get(Form("grV%i4", n));
//
//	gr.grC6 = (TGraphErrors*) f->Get(Form("grC%i6", n));
//	gr.grV6 = (TGraphErrors*) f->Get(Form("grV%i6", n));
//
//	gr.grC8 = (TGraphErrors*) f->Get(Form("grC%i8", n));
//	gr.grV8 = (TGraphErrors*) f->Get(Form("grV%i8", n));
//
//	gr.grV4->SetMarkerSize(2);
//	gr.grV6->SetMarkerSize(2);
//	gr.grV8->SetMarkerSize(2);
//
//	gr.grV4->SetMarkerStyle(kFullSquare);
//	gr.grV6->SetMarkerStyle(kFullCross);
//	gr.grV8->SetMarkerStyle(kFullDiamond);
//};

void plotL()
{
	TString s2pPb = "grV2_merged.root";
	TString s3pPb = "grV3_merged.root";
	TString s2PbPb = "grV2PbPb_GMO.root";
	TString s3PbPb = "grV3PbPb_GMO.root";
	TString s2pp = "grV2_pp13.root";
	TString s3pp = "grV3_pp13.root";

	TFile *f2pPb = new TFile(s2pPb.Data());
	TFile *f3pPb = new TFile(s3pPb.Data());
	TFile *f2PbPb = new TFile(s2PbPb.Data());
	TFile *f3PbPb = new TFile(s3PbPb.Data());
	TFile *f2pp = new TFile(s2pp.Data());
	TFile *f3pp = new TFile(s3pp.Data());

	HIN_16_022();
	published();

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

	TCanvas * cV = MakeCanvas("cV", "cV", 500, 500);
	TH2D * hframeV = new TH2D("hframeV", "", 1, 0, 399, 1, -0.03, 0.25);
	InitHist(hframeV, "N_{trk}^{offline}", "v_{n}{m}");

	/////// pPb v24
	hframeV->GetYaxis()->SetTitle("v_{2}{4}");
	hframeV->Draw();
	grPA2.grV4->SetMarkerStyle(kFullSquare);
	grPA2.grV4->Draw("psame");
	mgr_pPb_v24.Draw();

	TLegend * legV24 = new TLegend(0.4, 0.75, 0.85, 0.9);
	legV24->SetFillColor(kWhite);
	legV24->SetTextFont(42);
	legV24->SetTextSize(0.06);
	legV24->SetBorderSize(0);
	legV24->AddEntry(grPA2.grV4, "pPb 8 TeV", "p");
	legV24->AddEntry(mgr_pPb_v24.GetListOfGraphs()->At(0), "pPb 5 TeV", "p");
	legV24->Draw();

	cV->SaveAs("pPb_v24.pdf");

	/////// pPb v26
	hframeV->GetYaxis()->SetTitle("v_{2}{6}");
	hframeV->Draw();
	grPA2.grV6->Draw("psame");
	mgr_pPb_v26.Draw();

	TLegend * legV26 = new TLegend(0.4, 0.75, 0.85, 0.9);
	legV26->SetFillColor(kWhite);
	legV26->SetTextFont(42);
	legV26->SetTextSize(0.06);
	legV26->SetBorderSize(0);
	legV26->AddEntry(grPA2.grV6, "pPb 8 TeV", "p");
	legV26->AddEntry(mgr_pPb_v26.GetListOfGraphs()->At(0), "pPb 5 TeV", "p");
	legV26->Draw();

	cV->SaveAs("pPb_v26.pdf");

	/////// pPb v28
	hframeV->GetYaxis()->SetTitle("v_{2}{8}");
	hframeV->Draw();
	grPA2.grV8->Draw("psame");
	mgr_pPb_v28.Draw();

	TLegend * legV28 = new TLegend(0.4, 0.75, 0.85, 0.9);
	legV28->SetFillColor(kWhite);
	legV28->SetTextFont(42);
	legV28->SetTextSize(0.06);
	legV28->SetBorderSize(0);
	legV28->AddEntry(grPA2.grV8, "pPb 8 TeV", "p");
	legV28->AddEntry(mgr_pPb_v28.GetListOfGraphs()->At(0), "pPb 5 TeV", "p");
	legV28->Draw();

	cV->SaveAs("pPb_v28.pdf");

	/////// PbPb v24
	hframeV->GetYaxis()->SetTitle("v_{2}{4}");
	hframeV->Draw();
	grAA2.grV4->SetMarkerStyle(kFullSquare);
	grAA2.grV4->Draw("psame");
	mgr_PbPb_v24.Draw();

	TLegend * legV24AA = new TLegend(0.35, 0.75, 0.85, 0.9);
	legV24AA->SetFillColor(kWhite);
	legV24AA->SetTextFont(42);
	legV24AA->SetTextSize(0.06);
	legV24AA->SetBorderSize(0);
	legV24AA->AddEntry(grAA2.grV4, "PbPb 5 TeV", "p");
	legV24AA->AddEntry(mgr_PbPb_v24.GetListOfGraphs()->At(0), "PbPb 2.76 TeV", "p");
	legV24AA->Draw();

	cV->SaveAs("PbPb_v24.pdf");

	/////// PbPb v26
	hframeV->GetYaxis()->SetTitle("v_{2}{6}");
	hframeV->Draw();
	grAA2.grV6->Draw("psame");
	mgr_PbPb_v26.Draw();

	TLegend * legV26AA = new TLegend(0.35, 0.75, 0.85, 0.9);
	legV26AA->SetFillColor(kWhite);
	legV26AA->SetTextFont(42);
	legV26AA->SetTextSize(0.06);
	legV26AA->SetBorderSize(0);
	legV26AA->AddEntry(grAA2.grV6, "PbPb 5 TeV", "p");
	legV26AA->AddEntry(mgr_PbPb_v26.GetListOfGraphs()->At(0), "PbPb 2.76 TeV", "p");
	legV26AA->Draw();

	cV->SaveAs("PbPb_v26.pdf");


	/////// PbPb v28
	hframeV->GetYaxis()->SetTitle("v_{2}{8}");
	hframeV->Draw();
	grAA2.grV8->Draw("psame");
	mgr_PbPb_v28.Draw();

	TLegend * legV28AA = new TLegend(0.35, 0.75, 0.85, 0.9);
	legV28AA->SetFillColor(kWhite);
	legV28AA->SetTextFont(42);
	legV28AA->SetTextSize(0.06);
	legV28AA->SetBorderSize(0);
	legV28AA->AddEntry(grAA2.grV8, "PbPb 5 TeV", "p");
	legV28AA->AddEntry(mgr_PbPb_v28.GetListOfGraphs()->At(0), "PbPb 2.76 TeV", "p");
	legV28AA->Draw();

	cV->SaveAs("PbPb_v28.pdf");

}
