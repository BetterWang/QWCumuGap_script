
char const * fname[] = {
	"test/",			// 0
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_v5/170303_135919/0000/",			// 1 pPb HM0 standard
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_v5/170304_100734/0000/",			// 2 pPb HM1 standard
	"",			// 3 pPb HM2 standard
	"",			// 4 pPb HM3 standard
	"",			// 5 pPb HM4 standard
	"",			// 6 pPb HM5 standard
	"",			// 7 pPb HM6 standard
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_v5/170304_100748/0000/",			// 8 pPb HM7 standard
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_v5/170304_101121/0000/",				// 9 pPb MB1 standard
	"../pPb/PAMinimumBias2/crab_PAMB2_cumugap_eff_v4/170227_152727/0000/",				// 10 pPb MB2 standard
	"../pPb/PAMinimumBias3/crab_PAMB3_cumugap_eff_v4/170227_152748/0000/",				// 11 pPb MB3 standard
	"../pPb/PAMinimumBias4/crab_PAMB4_cumugap_eff_v4/170227_152827/0000/",				// 12 pPb MB4 standard
	"../pPb/PAMinimumBias5/crab_PAMB5_cumugap_eff_v4/170227_152848/0000/",				// 13 pPb MB5 standard
	"../pPb/PAMinimumBias6/crab_PAMB6_cumugap_eff_v4/170227_152904/0000/",				// 14 pPb MB6 standard
        "NA",			// 15 pPb MB sum standard
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_reverse_v5/170305_142853/0000/",		// 16 pPb HM0 reverse
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_reverse_v5/170305_142915/0000/",		// 17 pPb HM1 reverse
	"",			// 18 pPb HM2 reverse
	"",			// 19 pPb HM3 reverse
	"",			// 20 pPb HM4 reverse
	"",			// 21 pPb HM5 reverse
	"",			// 22 pPb HM6 reverse
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_reverse_v5/170305_142933/0000/",		// 23 pPb HM7 reverse
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_reverse_v5/170305_143849/0000/",			// 24 pPb MB1 reverse
	"",			// 25 pPb MB2 reverse
	"",			// 26 pPb MB3 reverse
	"",			// 27 pPb MB4 reverse
	"",			// 28 pPb MB5 reverse
	"",			// 29 pPb MB6 reverse
	"NA",		// 30 pPb MB sum reverse
	"../pPb/HighMultiplicity/crab_PPHM_totem_cumugap_eff_v1/170303_103746/0000/",			// 31 pp HM TOTEM
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_v2/170312_182749/0000/",	// 32 PbPb 5 TeV pp reco
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysTight_v5/170307_095900/0000/",		// 33 pPb HM0 8 TeV sysTight
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysTight_v5/170307_095914/0000/",		// 34 pPb HM1 8 TeV sysTight
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysTight_v5/170307_095927/0000/",		// 35 pPb HM7 8 TeV sysTight
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysTight_v5/170307_104005/0000/",			// 36 pPb MB1 8 TeV sysTight
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysTight_reverse_v5/170307_110237/0000/",	// 37 pPb HM0 reverse 8 TeV sysTight
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysTight_reverse_v5/170307_110252/0000/",	// 38 pPb HM1 reverse 8 TeV sysTight
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysTight_reverse_v5/170307_110307/0000/",	// 39 pPb HM7 reverse 8 TeV sysTight
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysTight_reverse_v5/170307_110742/0000/",		// 40 pPb MB1 reverse 8 TeV sysTight
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysLoose_v5/170307_132500/0000/",		// 41 pPb HM0 8 TeV sysLoose
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysLoose_v5/170307_132516/0000/",		// 42 pPb HM1 8 TeV sysLoose
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysLoose_v5/170307_132535/0000/",		// 43 pPb HM7 8 TeV sysLoose
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysLoose_v5/170307_172653/0000/",			// 44 pPb MB1 8 TeV sysLoose
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysLoose_reverse_v5/170307_132840/0000/",	// 45 pPb HM0 reverse 8 TeV sysLoose
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysLoose_reverse_v5/170307_132856/0000/",	// 46 pPb HM1 reverse 8 TeV sysLoose
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysLoose_reverse_v5/170307_132910/0000/",	// 47 pPb HM7 reverse 8 TeV sysLoose
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysLoose_reverse_v5/170307_172732/0000/",		// 48 pPb MB1 reverse 8 TeV sysLoose
	"NA",		// 49 pPb HM0 merged
	"NA",		// 50 pPb HM1 merged
	"NA",		// 51 pPb HM7 merged
	"NA",		// 52 pPb MB1 merged
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysNarrow_v5/170308_230455/0000/",		// 53 pPb HM0 8TeV sysNarrow
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysNarrow_v5/170308_230506/0000/",		// 54 pPb HM1 8TeV sysNarrow
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysNarrow_v5/170308_230517/0000/",		// 55 pPb HM7 8TeV sysNarrow
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysNarrow_v5/170308_230541/0000/",		// 56 pPb MB1 8TeV sysNarrow
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysNarrow_reverse_v5/170309_150207/0000/",	// 57 pPb HM0 reverse 8TeV sysNarrow
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysNarrow_reverse_v5/170309_150221/0000/",	// 58 pPb HM1 reverse 8TeV sysNarrow
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysNarrow_reverse_v5/170309_150234/0000/",	// 59 pPb HM7 reverse 8TeV sysNarrow
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysNarrow_reverse_v5/170309_150305/0000/",	// 60 pPb MB1 reverse 8TeV sysNarrow
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysWide_v5/170309_224329/0000/",		// 61 pPb HM0 8TeV sysWide
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysWide_v5/170309_224343/0000/",		// 62 pPb HM1 8TeV sysWide
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysWide_v5/170309_224356/0000/",		// 63 pPb HM7 8TeV sysWide
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysWide_v5/170309_224440/0000/",			// 64 pPb MB1 8TeV sysWide
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysWide_reverse_v5/170309_224555/0000/",	// 65 pPb HM0 8TeV reverse sysWide
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysWide_reverse_v5/170309_224609/0000/",	// 66 pPb HM1 8TeV reverse sysWide
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysWide_reverse_v5/170309_224622/0000/",	// 67 pPb HM7 8TeV reverse sysWide
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysWide_reverse_v5/170309_224723/0000/",		// 68 pPb MB1 8TeV reverse sysWide
	"NA",		// 69 pPb HM0 8 TeV sysTight merge
	"NA",		// 70 pPb HM1 8 TeV sysTight merge
	"NA",		// 71 pPb HM7 8 TeV sysTight merge
	"NA",		// 72 pPb MB1 8 TeV sysTight merge
	"NA",		// 73 pPb HM0 8 TeV sysLoose merge
	"NA",		// 74 pPb HM1 8 TeV sysLoose merge
	"NA",		// 75 pPb HM7 8 TeV sysLoose merge
	"NA",		// 76 pPb MB1 8 TeV sysLoose merge
	"NA",		// 77 pPb HM0 8 TeV sysNarrow merge
	"NA",		// 78 pPb HM1 8 TeV sysNarrow merge
	"NA",		// 79 pPb HM7 8 TeV sysNarrow merge
	"NA",		// 80 pPb MB1 8 TeV sysNarrow merge
	"NA",		// 81 pPb HM0 8 TeV sysWide merge
	"NA",		// 82 pPb HM1 8 TeV sysWide merge
	"NA",		// 83 pPb HM7 8 TeV sysWide merge
	"NA",		// 84 pPb MB1 8 TeV sysWide merge
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight_v2/170312_185101/0000/",	// 85 PbPb HIMB5 5 TeV pp reco sysTight
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysLoose_v2/170312_185152/0000/",	// 86 PbPb HIMB5 5 TeV pp reco sysLoose
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysNarrow_v2/170312_185233/0000/",	// 87 PbPb HIMB5 5 TeV pp reco sysNarrow
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysWide_v2/170312_185250/0000/",	// 88 PbPb HIMB5 5 TeV pp reco sysWide
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_rerun_v2/170316_064727/0000/",	// 89 PbPb HIMB6 5 TeV pp reco
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight_v2/170313_110422/0000/",	// 90 PbPb HIMB6 5 TeV pp reco sysTight
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysLoose_v2/170313_110442/0000/",	// 91 PbPb HIMB6 5 TeV pp reco sysLoose
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysNarrow_v2/170313_110507/0000/",	// 92 PbPb HIMB6 5 TeV pp reco sysNarrow
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysWide_v2/170313_110525/0000/",	// 93 PbPb HIMB6 5 TeV pp reco sysWide
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_v2/170314_095631/0000/",		// 94 PbPb HIMB7 5 TeV pp reco
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight_v2/170314_095724/0000/",	// 95 PbPb HIMB7 5 TeV pp reco sysTight
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysLoose_v2/170314_095834/0000/",	// 96 PbPb HIMB7 5 TeV pp reco sysLoose
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysNarrow_v2/170314_095946/0000/",	// 97 PbPb HIMB7 5 TeV pp reco sysNarrow
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysWide_v2/170314_095918/0000/",	// 98 PbPb HIMB7 5 TeV pp reco sysWide
	"NA",	// 99 PbPb merged HIMB5,6,7 5 TeV pp reco
	"NA",	// 100 PbPb merged HIMB5,6,7 5 TeV pp reco sysTight
	"NA",	// 101 PbPb merged HIMB5,6,7 5 TeV pp reco sysLoose
	"NA",	// 102 PbPb merged HIMB5,6,7 5 TeV pp reco sysNarrow
	"NA",	// 103 PbPb merged HIMB5,6,7 5 TeV pp reco sysWide
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysHLT_v5/170315_162034/0000/",		// 104 pPb HM0 8 TeV sysHLT
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysHLT_v5/170315_162053/0000/",		// 105 pPb HM1 8 TeV sysHLT
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysHLT_reverse_v5/170315_162418/0000/",	// 106 pPb HM0 8 TeV reverse sysHLT
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysHLT_reverse_v5/170315_162432/0000/",	// 107 pPb HM1 8 TeV reverse sysHLT
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysEff_v5/170315_165743/0000/",		// 108 pPb HM0 8 TeV sysEff
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysEff_v5/170315_165759/0000/",		// 109 pPb HM1 8 TeV sysEff
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysEff_v5/170315_165811/0000/",		// 110 pPb HM7 8 TeV sysEff
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysEff_v5/170315_165839/0000/",			// 111 pPb MB1 8 TeV sysEff
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysEff_reverse_v5/170315_165910/0000/",	// 112 pPb HM0 8 TeV reverse sysEff
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysEff_reverse_v5/170315_165933/0000/",	// 113 pPb HM1 8 TeV reverse sysEff
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysEff_reverse_v5/170315_165959/0000/",	// 114 pPb HM7 8 TeV reverse sysEff
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysEff_reverse_v5/170315_170104/0000/",		// 115 pPb MB1 8 TeV reverse sysEff
	"NA",		// 116 pPb HM0 8 TeV merge sysHLT
	"NA",		// 117 pPb HM1 8 TeV merge sysHLT
	"NA",		// 118 pPb HM0 8 TeV merge sysEff
	"NA",		// 119 pPb HM1 8 TeV merge sysEff
	"NA",		// 120 pPb HM7 8 TeV merge sysEff
	"NA",		// 121 pPb MB1 8 TeV merge sysEff
};

char const * ftxt[] = {
	"txt/test/",			// 0
	"txt/PAHM0/",			// 1
	"txt/PAHM1/",			// 2
	"txt/PAHM2/",			// 3
	"txt/PAHM3/",			// 4
	"txt/PAHM4/",			// 5
	"txt/PAHM5/",			// 6
	"txt/PAHM6/",			// 7
	"txt/PAHM7/",			// 8
	"txt/PAMB1/",			// 9
	"txt/PAMB2/",			// 10
	"txt/PAMB3/",			// 11
	"txt/PAMB4/",			// 12
	"txt/PAMB5/",			// 13
	"txt/PAMB6/",			// 14
	"txt/PAMB_full/",		// 15
	"txt/PAHM0_reverse/",		// 16
	"txt/PAHM1_reverse/",		// 17
	"txt/PAHM2_reverse/",		// 18
	"txt/PAHM3_reverse/",		// 19
	"txt/PAHM4_reverse/",		// 20
	"txt/PAHM5_reverse/",		// 21
	"txt/PAHM6_reverse/",		// 22
	"txt/PAHM7_reverse/",		// 23
	"txt/PAMB1_reverse/",		// 24
	"txt/PAMB2_reverse/",		// 25
	"txt/PAMB3_reverse/",		// 26
	"txt/PAMB4_reverse/",		// 27
	"txt/PAMB5_reverse/",		// 28
	"txt/PAMB6_reverse/",		// 29
	"txt/PAMB_reverse_full/",	// 30
	"txt/PP15_TOTEM/",		// 31
	"txt/PbPb15_ppreco/",		// 32
	"txt/PAHM0_sysTight/",		// 33
	"txt/PAHM1_sysTight/",		// 34
	"txt/PAHM7_sysTight/",		// 35
	"txt/PAMB1_sysTight/",		// 36
	"txt/PAHM0_sysTight_reverse/",		// 37
	"txt/PAHM1_sysTight_reverse/",		// 38
	"txt/PAHM7_sysTight_reverse/",		// 39
	"txt/PAMB1_sysTight_reverse/",		// 40
	"txt/PAHM0_sysLoose/",		// 41
	"txt/PAHM1_sysLoose/",		// 42
	"txt/PAHM7_sysLoose/",		// 43
	"txt/PAMB1_sysLoose/",		// 44
	"txt/PAHM0_sysLoose_reverse/",		// 45
	"txt/PAHM1_sysLoose_reverse/",		// 46
	"txt/PAHM7_sysLoose_reverse/",		// 47
	"txt/PAMB1_sysLoose_reverse/",		// 48
	"txt/PAHM0_merge/",		// 49
	"txt/PAHM1_merge/",		// 50
	"txt/PAHM7_merge/",		// 51
	"txt/PAMB1_merge/",		// 52
	"txt/PAHM0_sysNarrow/",			// 53
	"txt/PAHM1_sysNarrow/",			// 54
	"txt/PAHM7_sysNarrow/",			// 55
	"txt/PAMB1_sysNarrow/",			// 56
	"txt/PAHM0_sysNarrow_reverse/",		// 57
	"txt/PAHM1_sysNarrow_reverse/",		// 58
	"txt/PAHM7_sysNarrow_reverse/",		// 59
	"txt/PAMB1_sysNarrow_reverse/",		// 60
	"txt/PAHM0_sysWide/",			// 61
	"txt/PAHM1_sysWide/",			// 62
	"txt/PAHM7_sysWide/",			// 63
	"txt/PAMB1_sysWide/",			// 64
	"txt/PAHM0_sysWide_reverse/",		// 65
	"txt/PAHM1_sysWide_reverse/",		// 66
	"txt/PAHM7_sysWide_reverse/",		// 67
	"txt/PAMB1_sysWide_reverse/",		// 68
	"txt/PAHM0_sysTight_merge/",		// 69
	"txt/PAHM1_sysTight_merge/",		// 70
	"txt/PAHM7_sysTight_merge/",		// 71
	"txt/PAMB1_sysTight_merge/",		// 72
	"txt/PAHM0_sysLoose_merge/",		// 73
	"txt/PAHM1_sysLoose_merge/",		// 74
	"txt/PAHM7_sysLoose_merge/",		// 75
	"txt/PAMB1_sysLoose_merge/",		// 76
	"txt/PAHM0_sysNarrow_merge/",		// 77
	"txt/PAHM1_sysNarrow_merge/",		// 78
	"txt/PAHM7_sysNarrow_merge/",		// 79
	"txt/PAMB1_sysNarrow_merge/",		// 80
	"txt/PAHM0_sysWide_merge/",		// 81
	"txt/PAHM1_sysWide_merge/",		// 82
	"txt/PAHM7_sysWide_merge/",		// 83
	"txt/PAMB1_sysWide_merge/",		// 84
	"txt/PbPb15_ppreco_sysTight/",		// 85
	"txt/PbPb15_ppreco_sysLoose/",		// 86
	"txt/PbPb15_ppreco_sysNarrow/",		// 87
	"txt/PbPb15_ppreco_sysWide/",		// 88
	"txt/PbPb15_ppreco6/",			// 89
	"txt/PbPb15_ppreco6_sysTight/",		// 90
	"txt/PbPb15_ppreco6_sysLoose/",		// 91
	"txt/PbPb15_ppreco6_sysNarrow/",	// 92
	"txt/PbPb15_ppreco6_sysWide/",		// 93
	"txt/PbPb15_ppreco7/",			// 94
	"txt/PbPb15_ppreco7_sysTight/",		// 95
	"txt/PbPb15_ppreco7_sysLoose/",		// 96
	"txt/PbPb15_ppreco7_sysNarrow/",	// 97
	"txt/PbPb15_ppreco7_sysWide/",		// 98
	"txt/PbPb15_ppreco_merge/",		// 99
	"txt/PbPb15_ppreco_sysTight_merge/",	// 100
	"txt/PbPb15_ppreco_sysLoose_merge/",	// 101
	"txt/PbPb15_ppreco_sysNarrow_merge/",	// 102
	"txt/PbPb15_ppreco_sysWide_merge/",	// 103
	"txt/PAHM0_sysHLT/",			// 104
	"txt/PAHM1_sysHLT/",			// 105
	"txt/PAHM0_sysHLT_reverse/",		// 106
	"txt/PAHM1_sysHLT_reverse/",		// 107
	"txt/PAHM0_sysEff/",			// 108
	"txt/PAHM1_sysEff/",			// 109
	"txt/PAHM7_sysEff/",			// 110
	"txt/PAMB1_sysEff/",			// 111
	"txt/PAHM0_sysEff_reverse/",		// 112
	"txt/PAHM1_sysEff_reverse/",		// 113
	"txt/PAHM7_sysEff_reverse/",		// 114
	"txt/PAMB1_sysEff_reverse/",		// 115
	"txt/PAHM0_sysHLT_merge/",		// 116
	"txt/PAHM1_sysHLT_merge/",		// 117
	"txt/PAHM0_sysEff_merge/",		// 118
	"txt/PAHM1_sysEff_merge/",		// 119
	"txt/PAHM7_sysEff_merge/",		// 120
	"txt/PAMB1_sysEff_merge/",		// 121
};


#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumugap/trV", fname[s1]));
}
