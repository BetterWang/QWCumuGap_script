TMultiGraph mgr_PbPb_v22;
TMultiGraph mgr_PbPb_v24;
TMultiGraph mgr_PbPb_v26;
TMultiGraph mgr_PbPb_v28;

TMultiGraph mgr_pPb_v22;
TMultiGraph mgr_pPb_v24;
TMultiGraph mgr_pPb_v26;
TMultiGraph mgr_pPb_v28;

pair<TGraphErrors*, TGraphErrors*> getGr(string &s)
{
        istringstream iss(s);
        vector<double> Noff, v2, v2e, v2s;
        while (!iss.eof())
        {
                double x, y, e, sys;
                iss >> x >> y >> e >> sys;
                Noff.push_back(x);
                v2.push_back(y);
                v2e.push_back(e);
                v2s.push_back(sys);
        }
        gr  = new TGraphErrors(Noff.size(), &Noff[0], &v2[0], 0, &v2e[0]);
        grs = new TGraphErrors(Noff.size(), &Noff[0], &v2[0], 0, &v2s[0]);
	gr->SetMarkerSize(2.);
        return std::make_pair(gr, grs);
}

void published()
{

//NtrkOffline,  v2,  stat.err,  sys.err
//PbPb, v22:
string v22PbPb =
"6.967   0.04862   0.004403    0.001459 "
"14.22   0.05233   0.001615    0.00157 "
"24.3    0.05476   0.001056    0.001643 "
"34.34   0.05762   0.0007978   0.001729 "
"44.37   0.06139   0.0006379   0.001842 "
"54.39   0.06476   0.0005337   0.001943 "
"69.1    0.07128   0.0002986   0.002138 "
"89.21   0.07666   0.000239    0.0023 "
"109.3   0.08179   0.0001984   0.002454 "
"134.1   0.08609   0.0001364   0.002583 "
"166.5   0.09026   0.0001058   0.002708 "
"201.6   0.09364   9.088e-05   0.002809 "
"229.4   0.09594   0.0001086   0.002878 "
"249.4   0.09672   0.0001023   0.002902 "
"269.4   0.09802   9.647e-05   0.002941 "
"289.4   0.09909   9.123e-05   0.002973 "
"309.4   0.0999    8.688e-05   0.002997 "
"334.3   0.1005    6.729e-05   0.003015 "
;
//PbPb, v22, peripheral subtraction:
//24.3    0.03562   0.002246
//34.34   0.04343   0.001494
//44.37   0.05024   0.001111
//54.39   0.05565   0.0008841
//69.1    0.06457   0.0005586
//89.21   0.07154   0.0004248
//109.3   0.07768   0.0003413
//134.1   0.08279   0.0002575
//166.5   0.08759   0.0002047
//201.6   0.09143   0.0001702
//229.4   0.09398   0.0001683
//249.4   0.09489   0.0001576
//269.4   0.09633   0.0001469
//289.4   0.09751   0.0001375
//309.4   0.09839   0.0001311
//334.3   0.09913   0.0001118

//PbPb, v24:
string v24PbPb =
"34.34   0.0398    0.01727     0.001194 "
"44.37   0.05425   0.005501    0.001627 "
"54.39   0.05399   0.004521    0.00162  "
"69.11   0.05996   0.001912    0.001799 "
"89.21   0.0641    0.001249    0.001923 "
"109.3   0.06684   0.0009372   0.002005 "
"134.1   0.07102   0.0005783   0.002131 "
"166.5   0.07426   0.0004147   0.002228 "
"201.6   0.07692   0.000347    0.002308 "
"229.4   0.07842   0.0004179   0.002353 "
"249.4   0.08031   0.0003848   0.002409 "
"269.4   0.08057   0.000382    0.002417 "
"289.4   0.08251   0.0003449   0.002475 "
"309.4   0.08261   0.0003349   0.002478 "
"334.3   0.08355   0.0002693   0.002507 "
;
//pPb, v22:
string v22pPb =
"6.917   0.05367   0.001655    0.002093 "
"14.37   0.05428   0.0006222   0.002117 "
"24.41   0.05379   0.0003994   0.002098 "
"34.39   0.05501   0.0002977   0.002145 "
"44.36   0.05651   0.0002436   0.002204 "
"54.33   0.05814   0.0002135   0.002267 "
"68.63   0.06038   0.0001381   0.002355 "
"88.39   0.0629    0.0001397   0.002453 "
"108.2   0.06421   0.0001624   0.002504 "
"131.3   0.06633   4.268e-05   0.002587 "
"162.1   0.06777   3.212e-05   0.002643 "
"196.6   0.06887   2.831e-05   0.002686 "
"227.5   0.06927   4.645e-05   0.00381 "
"247.2   0.0697    8.416e-05   0.003833 "
"267.1   0.06977   0.0001636   0.005163 "
"287     0.06896   0.0003366   0.005103 "
"306.8   0.06706   0.000741    0.004962 "
"328.6   0.06621   0.00147     0.0049 "
;
//pPb, v22, peripheral subtraction:
//24.41   0.03175   0.000973
//34.39   0.03825   0.0006441
//44.36   0.04299   0.000488
//54.33   0.04683   0.0003991
//68.63   0.05128   0.0002845
//88.39   0.05569   0.0002399
//108.2   0.05821   0.0002327
//131.3   0.06133   0.000131
//162.1   0.06364   0.0001061
//196.6   0.06537   8.969e-05
//227.5   0.06618   8.881e-05
//247.2   0.06684   0.0001114
//267.1   0.06707   0.0001821
//287     0.0664    0.000355
//306.8   0.06455   0.0007721
//328.6   0.06365   0.00153

//pPb, v24:
string v24pPb =
"44.36   0.02965   0.005967    0.003173 "
"54.33   0.03913   0.004262    0.004187 "
"68.63   0.04832   0.001496    0.003093 "
"88.39   0.04941   0.001351    0.003162 "
"108.2   0.04822   0.001599    0.001977 "
"131.3   0.04955   0.0003922   0.002032 "
"162.1   0.049     0.0003065   0.002009 "
"196.6   0.04805   0.0002939   0.00197 "
"227.5   0.04709   0.0004568   0.002637 "
"247.2   0.04665   0.0008684   0.002612 "
"269.2   0.04772   0.001471    0.003579 "
"301.2   0.04797   0.004329    0.003598 "
;

// PbPb 2.76 TeV v26
string v26PbPb =
"334.3	0.08249   0.00031          0.00152 "
"309.4	0.08148   0.00029          0.00151 "
"289.4	0.08098   0.00035          0.00160 "
"269.4	0.07946   0.00036          0.00149 "
"249.4	0.0788    0.0003           0.0015 "
"229.4	0.07748   0.00035          0.00141 "
"201.6	0.07574   0.00036          0.00145 "
"166.5	0.07294   0.00042          0.00136 "
"134.1	0.06989   0.00046          0.00127 "
"109.3	0.06541   0.00086          0.00160 "
"89.2	0.06483   0.00112          0.00096 "
"69.12	0.05985   0.00226          0.00150 "
"54.38	0.06082   0.00427          0.00195 "
;
// PbPb 2.76 TeV v28
string v28PbPb =
"334.3	0.08233   0.00035          0.00151 "
"309.4	0.08132   0.00034          0.00151 "
"289.4	0.08064   0.00044          0.00160 "
"269.4	0.07918   0.00043          0.00147 "
"249.4	0.07842   0.00041          0.00144 "
"229.4	0.07721   0.00042          0.00141 "
"201.6	0.0755    0.0005           0.0014  "
"166.5	0.0725    0.0006           0.0014  "
"134.1	0.06946   0.00064          0.00126 "
"109.3	0.06543   0.00131          0.00154 "
"89.2	0.06504   0.00159          0.00093 "
"69.1	0.0638    0.0026           0.0037  "
;
// pPb 5 TeV v26
string v26pPb =
"270.5	0.0485    0.0040           0.0024  "
"247.2	0.04013   0.00308          0.00201 "
"227.5	0.04462   0.00096          0.00223 "
"196.7	0.04495   0.00059          0.00225 "
"162.1	0.04491   0.00068          0.00225 "
"131.3	0.04695   0.00115          0.00235 "
"108.2	0.04862   0.00403          0.00243 "
;
// pPb 5 TeV v28
string v28pPb =
"196.7	0.04282   0.00227          0.00257 "
"162.1	0.04504   0.00203          0.00270 "
"131.3	0.04619   0.00227          0.00277 "
"108.2	0.05654   0.00248          0.00339 "
;

	auto grp = getGr(v22PbPb);
	grp.first->SetMarkerStyle(kOpenCircle);
	grp.first->SetMarkerColor(kRed);
	grp.first->SetLineColor(kRed);
	mgr_PbPb_v22.Add(grp.first, "p");

	grp = getGr(v24PbPb);
	grp.first->SetMarkerStyle(kOpenSquare);
	grp.first->SetMarkerColor(kBlue);
	grp.first->SetLineColor(kBlue);
	mgr_PbPb_v24.Add(grp.first, "p");

	grp = getGr(v26PbPb);
	grp.first->SetMarkerStyle(kOpenCross);
	grp.first->SetMarkerColor(kBlue);
	grp.first->SetLineColor(kBlue);
	mgr_PbPb_v26.Add(grp.first, "p");

	grp = getGr(v28PbPb);
	grp.first->SetMarkerStyle(kOpenDiamond);
	grp.first->SetMarkerColor(kRed);
	grp.first->SetLineColor(kRed);
	mgr_PbPb_v28.Add(grp.first, "p");

	//
	grp = getGr(v22pPb);
	grp.first->SetMarkerStyle(kOpenCircle);
	grp.first->SetMarkerColor(kRed);
	grp.first->SetLineColor(kRed);
	mgr_pPb_v22.Add(grp.first, "p");

	grp = getGr(v24pPb);
	grp.first->SetMarkerStyle(kOpenSquare);
	grp.first->SetMarkerColor(kBlue);
	grp.first->SetLineColor(kBlue);
	mgr_pPb_v24.Add(grp.first, "p");

	grp = getGr(v26pPb);
	grp.first->SetMarkerStyle(kOpenCross);
	grp.first->SetMarkerColor(kBlue);
	grp.first->SetLineColor(kBlue);
	mgr_pPb_v26.Add(grp.first, "p");

	grp = getGr(v28pPb);
	grp.first->SetMarkerStyle(kOpenDiamond);
	grp.first->SetMarkerColor(kRed);
	grp.first->SetLineColor(kRed);
	mgr_pPb_v28.Add(grp.first, "p");

}