
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
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysHighPU_v5/170316_132626/0000/",		// 122 pPb HM0 8 TeV sysHighPU
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysHighPU_v5/170316_132646/0000/",		// 123 pPb HM1 8 TeV sysHighPU
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysHighPU_v5/170316_132707/0000/",		// 124 pPb HM7 8 TeV sysHighPU
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysHighPU_v5/170316_133426/0000/",		// 125 pPb MB1 8 TeV sysHighPU
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysHighPU_reverse_v5/170316_133946/0000/",	// 126 pPb HM0 8 TeV reverse sysHighPU
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysHighPU_reverse_v5/170316_134003/0000/",	// 127 pPb HM1 8 TeV reverse sysHighPU
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysHighPU_reverse_v5/170316_134023/0000/",	// 128 pPb HM7 8 TeV reverse sysHighPU
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysHighPU_reverse_v5/170316_134225/0000/",	// 129 pPb MB1 8 TeV reverse sysHighPU
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysLowPU_v5/170316_132915/0000/",		// 130 pPb HM0 8 TeV sysLowPU
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysLowPU_v5/170316_132937/0000/",		// 131 pPb HM1 8 TeV sysLowPU
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysLowPU_v5/170316_132952/0000/",		// 132 pPb HM7 8 TeV sysLowPU
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysLowPU_v5/170316_134703/0000/",			// 133 pPb MB1 8 TeV sysLowPU
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_sysLowPU_reverse_v5/170316_134109/0000/",	// 134 pPb HM0 8 TeV reverse sysLowPU
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_sysLowPU_reverse_v5/170316_134124/0000/",	// 135 pPb HM1 8 TeV reverse sysLowPU
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_sysLowPU_reverse_v5/170316_134140/0000/",	// 136 pPb HM7 8 TeV reverse sysLowPU
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_sysLowPU_reverse_v5/170316_134802/0000/",		// 137 pPb MB1 8 TeV reverse sysLowPU
	"NA",		// 138 pPb HM0 8 TeV merge sysHighPU
	"NA",		// 139 pPb HM1 8 TeV merge sysHighPU
	"NA",		// 140 pPb HM7 8 TeV merge sysHighPU
	"NA",		// 141 pPb MB1 8 TeV merge sysHighPU
	"NA",		// 142 pPb HM0 8 TeV merge sysLowPU
	"NA",		// 143 pPb HM1 8 TeV merge sysLowPU
	"NA",		// 144 pPb HM7 8 TeV merge sysLowPU
	"NA",		// 145 pPb MB1 8 TeV merge sysLowPU
	"../PbPb2015_cumu/MC/HIJING/",							// 146 HIJING 5-10fm fEllP_8pct_v2 non-flow
	"../PbPb2015_cumu/MC/Hydjet5-10_fNhsel0/",					// 147 Hydjet 5-10cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet5-10_fNhsel2/",					// 148 Hydjet 5-10cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet5-10_fNhsel4/",					// 149 Hydjet 5-10cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/Hydjet20-25_fNhsel0/",					// 150 Hydjet 20-25cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet20-25_fNhsel2/",					// 151 Hydjet 20-25cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet20-25_fNhsel4/",					// 152 Hydjet 20-25cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/Hydjet35-40_fNhsel0/",					// 153 Hydjet 35-40cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet35-40_fNhsel2/",					// 154 Hydjet 35-40cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet35-40_fNhsel4/",					// 155 Hydjet 35-40cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/HIJING_mod1/",						// 156 HIJING 5-10fm fEllP_8pct_v2 without non-flow
	"../PbPb2015_cumu/MC/HIJING_mod0/",						// 157 HIJING 5-10fm flow off
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysPxLayer1_v4/170407_141154/0000/",	// 158 PbPb 5 TeV ppreco HIMB5 sysPxLayer1
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysPxLayer1_v4/170407_141211/0000/",	// 159 PbPb 5 TeV ppreco HIMB6 sysPxLayer1
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysPxLayer1_v4/170407_141229/0000/",	// 160 PbPb 5 TeV ppreco HIMB7 sysPxLayer1
	"NA",		// 161 PbPb 5 TeV ppreco HIMB567 sysPxLayer1
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2_v2/170406_102854/0000/",		// 162 PbPb 5 TeV ppreco HIMB5 sysTight2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight3_v2/170406_090218/0000/",		// 163 PbPb 5 TeV ppreco HIMB5 sysTight3 dzdzerror = d0d0error = 3.0 pterrorpt = 0.05
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTighter_v2/170406_090248/0000/",		// 164 PbPb 5 TeV ppreco HIMB5 sysTighter dzdzerror = d0d0error = 2.0 pterrorpt = 0.05
	"../PbPb2015_cumu/MC/Hydjet10-15_fNhsel0/",					// 165 Hydjet 10-15cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet10-15_fNhsel2/",					// 166 Hydjet 10-15cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet10-15_fNhsel4/",					// 167 Hydjet 10-15cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/Hydjet15-20_fNhsel0/",					// 168 Hydjet 15-20cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet15-20_fNhsel2/",					// 169 Hydjet 15-20cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet15-20_fNhsel4/",					// 170 Hydjet 15-20cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/Hydjet25-30_fNhsel0/",					// 171 Hydjet 25-30cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet25-30_fNhsel2/",					// 172 Hydjet 25-30cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet25-30_fNhsel4/",					// 173 Hydjet 25-30cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/MC/Hydjet30-35_fNhsel0/",					// 174 Hydjet 10-15cent pure hydro (jets (nonflow) off),
	"../PbPb2015_cumu/MC/Hydjet30-35_fNhsel2/",					// 175 Hydjet 10-15cent full sample (hydro+jets (nonflow))
	"../PbPb2015_cumu/MC/Hydjet30-35_fNhsel4/",					// 176 Hydjet 10-15cent only jets (nonflow) (hydro off)
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_CumuGap_Pixel_eff_cent_v1/170407_093344/0000/",			// 177 PbPb HIMB2 Pixel 0.3<pT<3.0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysStd_v2/170407_182700/0000/",	// 178 PbPb HIMB5 5 TeV pp reco sysStd
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysStd_v2/170407_183134/0000/",	// 179 PbPb HIMB6 5 TeV pp reco sysStd
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysStd_v2/170407_182715/0000/",	// 180 PbPb HIMB7 5 TeV pp reco sysStd
	"NA",	// 181 PbPb HIMB567 5 TeV pp reco sysStd
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2_v2/170411_100355/0000/",		// 182 PbPb 5 TeV ppreco HIMB6 sysTight2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2_v2/170411_100419/0000/",		// 183 PbPb 5 TeV ppreco HIMB7 sysTight2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1
	"NA",		// 184 PbPb 5 TeV ppreco HIMB567 sysTight2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysWide2_v2/170412_094102/0000/",		// 185 PbPb 5 TeV ppreco HIMB5 sysWide2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 3<|vz|<15
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysWide2_v2/170412_094134/0000/",		// 186 PbPb 5 TeV ppreco HIMB6 sysWide2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 3<|vz|<15
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysWide2_v2/170412_094212/0000/",		// 187 PbPb 5 TeV ppreco HIMB7 sysWide2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 3<|vz|<15
	"NA",		// 188 PbPb 5 TeV ppreco HIMB567 sysWide2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 3<|vz|<15
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysNarrow2_v2/170412_094331/0000/",		// 189 PbPb 5 TeV ppreco HIMB5 sysNarrow2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 0<|vz|<3
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysNarrow2_v2/170412_094352/0000/",		// 190 PbPb 5 TeV ppreco HIMB6 sysNarrow2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 0<|vz|<3
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysNarrow2_v2/170412_094419/0000/",		// 191 PbPb 5 TeV ppreco HIMB7 sysNarrow2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 0<|vz|<3
	"NA",		// 192 PbPb 5 TeV ppreco HIMB567 sysWide2 dzdzerror = d0d0error = 2.0 pterrorpt = 0.1 0<|vz|<3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_CumuGap_Pixel_eff_cent_sysPos_v1/170411_165838/0000/",		// 193 PbPb HIMB2 Pixel 0.3<pT<3.0 eta>0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_CumuGap_Pixel_eff_cent_sysNeg_v2/170420_120412/0000/",		// 194 PbPb HIMB2 Pixel 0.3<pT<3.0 eta<0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2dz_v2/170420_083825/0000/",	// 195 PbPb 5 TeV ppreco HIMB5 sysTight2dz
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2dz_v2/170420_083846/0000/",	// 196 PbPb 5 TeV ppreco HIMB6 sysTight2dz
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2dz_v2/170420_083907/0000/",	// 197 PbPb 5 TeV ppreco HIMB7 sysTight2dz
	"NA",	// 198 PbPb 5 TeV ppreco HIMB567 sysTight2dz
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2dxy_v2/170420_083930/0000/",	// 199 PbPb 5 TeV ppreco HIMB5 sysTight2dxy
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2dxy_v2/170420_083953/0000/",	// 200 PbPb 5 TeV ppreco HIMB6 sysTight2dxy
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2dxy_v2/170420_084015/0000/",	// 201 PbPb 5 TeV ppreco HIMB7 sysTight2dxy
	"NA",	// 202 PbPb 5 TeV ppreco HIMB567 sysTight2dxy
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2PosEta_v3/170428_092632/0000/",	// 203 PbPb 5 TeV ppreco HIMB5 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2PosEta_v3/170428_092647/0000/",	// 204 PbPb 5 TeV ppreco HIMB6 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2PosEta_v3/170428_092701/0000/",	// 205 PbPb 5 TeV ppreco HIMB7 sysTight2PosEta
	"NA",	// 206 PbPb 5 TeV ppreco HIMB567 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2NegEta_v3/170428_092744/0000/",	// 207 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2NegEta_v3/170428_092730/0000/",	// 208 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2NegEta_v3/170428_092744/0000/",	// 209 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"NA",	// 210 PbPb 5 TeV ppreco HIMB567 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2PosEta_v4/170503_080929/0000/",	// 211 PbPb 5 TeV ppreco HIMB5 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2PosEta_v4/170503_080945/0000/",	// 212 PbPb 5 TeV ppreco HIMB6 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2PosEta_v4/170503_081002/0000/",	// 213 PbPb 5 TeV ppreco HIMB7 sysTight2PosEta
	"NA",	// 214 PbPb 5 TeV ppreco HIMB567 sysTight2PosEta
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTight2NegEta_v5/170504_095034/0000/",	// 215 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias6/crab_HIMB6_CumuGap_ppReco_eff_noff_sysTight2NegEta_v5/170504_095050/0000/",	// 216 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias7/crab_HIMB7_CumuGap_ppReco_eff_noff_sysTight2NegEta_v5/170504_095107/0000/",	// 217 PbPb 5 TeV ppreco HIMB5 sysTight2NegEta
	"NA",	// 218 PbPb 5 TeV ppreco HIMB567 sysTight2NegEta
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysEta1_v2/170516_092708/0000/",		// 219 PbPb 5 TeV ppreco HIMB5 sysEta1 |eta|<1
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysLooseEta1_v2/170516_090207/0000/",	// 220 PbPb 5 TeV ppreco HIMB5 sysLooseEta1 |eta|<1
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_sysTightEta1_v2/170516_092725/0000/",	// 221 PbPb 5 TeV ppreco HIMB5 sysTightEta1 |eta|<1
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
	"txt/PAHM0_sysHighPU/",			// 122
	"txt/PAHM1_sysHighPU/",			// 123
	"txt/PAHM7_sysHighPU/",			// 124
	"txt/PAMB1_sysHighPU/",			// 125
	"txt/PAHM0_sysHighPU_reverse/",		// 126
	"txt/PAHM1_sysHighPU_reverse/",		// 127
	"txt/PAHM7_sysHighPU_reverse/",		// 128
	"txt/PAMB1_sysHighPU_reverse/",		// 129
	"txt/PAHM0_sysLowPU/",			// 130
	"txt/PAHM1_sysLowPU/",			// 131
	"txt/PAHM7_sysLowPU/",			// 132
	"txt/PAMB1_sysLowPU/",			// 133
	"txt/PAHM0_sysLowPU_reverse/",		// 134
	"txt/PAHM1_sysLowPU_reverse/",		// 135
	"txt/PAHM7_sysLowPU_reverse/",		// 136
	"txt/PAMB1_sysLowPU_reverse/",		// 137
	"txt/PAHM0_sysHighPU_merge/",		// 138
	"txt/PAHM1_sysHighPU_merge/",		// 139
	"txt/PAHM7_sysHighPU_merge/",		// 140
	"txt/PAMB1_sysHighPU_merge/",		// 141
	"txt/PAHM0_sysLowPU_merge/",		// 142
	"txt/PAHM1_sysLowPU_merge/",		// 143
	"txt/PAHM7_sysLowPU_merge/",		// 144
	"txt/PAMB1_sysLowPU_merge/",		// 145
	"txt/HIJING_fEllP_8pct_v2/",		// 146
	"txt/Hydjet5-10_0/",			// 147
	"txt/Hydjet5-10_2/",			// 148
	"txt/Hydjet5-10_4/",			// 149
	"txt/Hydjet20-25_0/",			// 150
	"txt/Hydjet20-25_2/",			// 151
	"txt/Hydjet20-25_4/",			// 152
	"txt/Hydjet35-40_0/",			// 153
	"txt/Hydjet35-40_2/",			// 154
	"txt/Hydjet35-40_4/",			// 155
	"txt/HIJING_fEllP_8pct_v2_mod1/",	// 156
	"txt/HIJING_mod0/",			// 157
	"txt/PbPb15_ppreco5_sysPxLayer1/",	// 158
	"txt/PbPb15_ppreco6_sysPxLayer1/",	// 159
	"txt/PbPb15_ppreco7_sysPxLayer1/",	// 160
	"txt/PbPb15_ppreco_sysPxLayer1/",	// 161
	"txt/PbPb15_ppreco5_sysTight2/",	// 162
	"txt/PbPb15_ppreco_sysTight3/",		// 163
	"txt/PbPb15_ppreco_sysTighter/",	// 164
	"txt/Hydjet10-15_0/",			// 165
	"txt/Hydjet10-15_2/",			// 166
	"txt/Hydjet10-15_4/",			// 167
	"txt/Hydjet15-20_0/",			// 168
	"txt/Hydjet15-20_2/",			// 169
	"txt/Hydjet15-20_4/",			// 170
	"txt/Hydjet25-30_0/",			// 171
	"txt/Hydjet25-30_2/",			// 172
	"txt/Hydjet25-30_4/",			// 173
	"txt/Hydjet30-35_0/",			// 174
	"txt/Hydjet30-35_2/",			// 175
	"txt/Hydjet30-35_4/",			// 176
	"txt/PbPb15_pixel/",			// 177
	"txt/PbPb15_ppreco5_sysStd/",		// 178
	"txt/PbPb15_ppreco6_sysStd/",		// 179
	"txt/PbPb15_ppreco7_sysStd/",		// 180
	"txt/PbPb15_ppreco_sysStd/",		// 181
	"txt/PbPb15_ppreco6_sysTight2/",	// 182
	"txt/PbPb15_ppreco7_sysTight2/",	// 183
	"txt/PbPb15_ppreco_sysTight2/",		// 184
	"txt/PbPb15_ppreco5_sysWide2/",		// 185
	"txt/PbPb15_ppreco6_sysWide2/",		// 186
	"txt/PbPb15_ppreco7_sysWide2/",		// 187
	"txt/PbPb15_ppreco_sysWide2/",		// 188
	"txt/PbPb15_ppreco5_sysNarrow2/",	// 189
	"txt/PbPb15_ppreco6_sysNarrow2/",	// 190
	"txt/PbPb15_ppreco7_sysNarrow2/",	// 191
	"txt/PbPb15_ppreco_sysNarrow2/",	// 192
	"txt/PbPb15_pixel_sysPos/",		// 193
	"txt/PbPb15_pixel_sysNeg/",		// 194
	"txt/PbPb15_ppreco5_sysTight2dz/",		// 195
	"txt/PbPb15_ppreco6_sysTight2dz/",		// 196
	"txt/PbPb15_ppreco7_sysTight2dz/",		// 197
	"txt/PbPb15_ppreco_sysTight2dz/",		// 198
	"txt/PbPb15_ppreco5_sysTight2dxy/",		// 199
	"txt/PbPb15_ppreco6_sysTight2dxy/",		// 200
	"txt/PbPb15_ppreco7_sysTight2dxy/",		// 201
	"txt/PbPb15_ppreco_sysTight2dxy/",		// 202
	"txt/PbPb15_ppreco5_sysTight2PosEta/",		// 203
	"txt/PbPb15_ppreco6_sysTight2PosEta/",		// 204
	"txt/PbPb15_ppreco7_sysTight2PosEta/",		// 205
	"txt/PbPb15_ppreco_sysTight2PosEta/",		// 206
	"txt/PbPb15_ppreco5_sysTight2NegEta/",		// 207
	"txt/PbPb15_ppreco6_sysTight2NegEta/",		// 208
	"txt/PbPb15_ppreco7_sysTight2NegEta/",		// 209
	"txt/PbPb15_ppreco_sysTight2NegEta/",		// 210
	"txt/PbPb15_ppreco5_sysTight2PosEta2/",		// 211
	"txt/PbPb15_ppreco6_sysTight2PosEta2/",		// 212
	"txt/PbPb15_ppreco7_sysTight2PosEta2/",		// 213
	"txt/PbPb15_ppreco_sysTight2PosEta2/",		// 214
	"txt/PbPb15_ppreco5_sysTight2NegEta2/",		// 215
	"txt/PbPb15_ppreco6_sysTight2NegEta2/",		// 216
	"txt/PbPb15_ppreco7_sysTight2NegEta2/",		// 217
	"txt/PbPb15_ppreco_sysTight2NegEta2/",		// 218
	"txt/PbPb15_ppreco5_sysEta1/",			// 219
	"txt/PbPb15_ppreco5_sysLooseEta1/",		// 220
	"txt/PbPb15_ppreco5_sysTightEta1/",		// 221
};


#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumugap/trV", fname[s1]));
}
