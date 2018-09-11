################## Beam
root -l -b -q 'compare3.C("grV2_pPb_sysPhiAcc.root", "grV2_Pbp_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV24",  "comp_pPb_sysBeam_v24.pdf",           "v_{2}{4} pPb",          "v_{2}{4} Pbp",          "v_{2}{4}",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV3_pPb_sysPhiAcc.root", "grV3_Pbp_sysPhiAcc.root", "grV3_sysPhiAcc.root", "grV34",  "comp_pPb_sysBeam_v34.pdf",           "v_{3}{4} pPb",          "v_{3}{4} Pbp",          "v_{3}{4}",          "v_{3}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2_pPb_sysPhiAcc.root", "grV2_Pbp_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV26",  "comp_pPb_sysBeam_v26.pdf",           "v_{2}{6} pPb",          "v_{2}{6} Pbp",          "v_{2}{6}",          "v_{2}{6}", 0.01)'
root -l -b -q 'compare3.C("grV2_pPb_sysPhiAcc.root", "grV2_Pbp_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV28",  "comp_pPb_sysBeam_v28.pdf",           "v_{2}{8} pPb",          "v_{2}{8} Pbp",          "v_{2}{8}",          "v_{2}{8}", 0.01)'
root -l -b -q 'compare3.C("grV2_pPb_sysPhiAcc.root", "grV2_Pbp_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV264", "comp_pPb_sysBeam_v264.pdf", "v_{2}{6}/v_{2}{4} pPb", "v_{2}{6}/v_{2}{4} Pbp", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_pPb_sysPhiAcc.root", "grV2_Pbp_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV286", "comp_pPb_sysBeam_v286.pdf", "v_{2}{8}/v_{2}{6} pPb", "v_{2}{8}/v_{2}{6} Pbp", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}", 0.03)'

############## PU
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grV24",  "comp_pPb_PU_v24.pdf", "v_{2}{4} HighPU",          "v_{2}{4} LowPU",                   "v_{2}{4} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root",  "grV34",  "comp_pPb_PU_v34.pdf", "v_{3}{4} HighPU",          "v_{3}{4} LowPU",                   "v_{3}{4} standard",          "v_{3}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grV26",  "comp_pPb_PU_v26.pdf", "v_{2}{6} HighPU",          "v_{2}{6} LowPU",                   "v_{2}{6} standard",          "v_{2}{6}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grV28",  "comp_pPb_PU_v28.pdf", "v_{2}{8} HighPU",          "v_{2}{8} LowPU",                   "v_{2}{8} standard",          "v_{2}{8}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV264", "comp_pPb_PU_v264.pdf", "v_{2}{6}/v_{2}{4} HighPU", "v_{2}{6}/v_{2}{4} LowPU", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV286", "comp_pPb_PU_v286.pdf", "v_{2}{8}/v_{2}{6} HighPU", "v_{2}{8}/v_{2}{6} LowPU", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}", 0.01)'

################ HLT
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grV24",  "comp_pPb_HLT_v24.pdf", " ",          "v_{2}{4} HLT",          "v_{2}{4} standard",          "v_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root",  "grV34",  "comp_pPb_HLT_v34.pdf", " ",          "v_{3}{4} HLT",          "v_{3}{4} standard",          "v_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grV26",  "comp_pPb_HLT_v26.pdf", " ",          "v_{2}{6} HLT",          "v_{2}{6} standard",          "v_{2}{6}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grV28",  "comp_pPb_HLT_v28.pdf", " ",          "v_{2}{8} HLT",          "v_{2}{8} standard",          "v_{2}{8}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV264", "comp_pPb_HLT_v264.pdf", " ", "v_{2}{6}/v_{2}{4} HLT", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV286", "comp_pPb_HLT_v286.pdf", " ", "v_{2}{8}/v_{2}{6} HLT", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}")'

############### tracking
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grV24",  "comp_pPb_trk_v24.pdf", "v_{2}{4} Tight",          "v_{2}{4} Loose",                   "v_{2}{4} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root",  "grV34",  "comp_pPb_trk_v34.pdf", "v_{3}{4} Tight",          "v_{3}{4} Loose",                   "v_{3}{4} standard",          "v_{3}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grV26",  "comp_pPb_trk_v26.pdf", "v_{2}{6} Tight",          "v_{2}{6} Loose",                   "v_{2}{6} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grV28",  "comp_pPb_trk_v28.pdf", "v_{2}{8} Tight",          "v_{2}{8} Loose",                   "v_{2}{8} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV264", "comp_pPb_trk_v264.pdf", "v_{2}{6}/v_{2}{4} Tight", "v_{2}{6}/v_{2}{4} Loose", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV286", "comp_pPb_trk_v286.pdf", "v_{2}{8}/v_{2}{6} Tight", "v_{2}{8}/v_{2}{6} Loose", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}", 0.02)'


############### vertex
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grV24", "comp_pPb_vz_v24.pdf",           "v_{2}{4} |vz|<3.0",          "v_{2}{4} 3.0<|vz|<15.",          "v_{2}{4} |vz|<15.",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root",  "grV34", "comp_pPb_vz_v34.pdf",           "v_{3}{4} |vz|<3.0",          "v_{3}{4} 3.0<|vz|<15.",          "v_{3}{4} |vz|<15.",          "v_{3}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grV26", "comp_pPb_vz_v26.pdf",           "v_{2}{6} |vz|<3.0",          "v_{2}{6} 3.0<|vz|<15.",          "v_{2}{6} |vz|<15.",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grV28", "comp_pPb_vz_v28.pdf",           "v_{2}{8} |vz|<3.0",          "v_{2}{8} 3.0<|vz|<15.",          "v_{2}{8} |vz|<15.",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV264", "comp_pPb_vz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3.0", "v_{2}{6}/v_{2}{4} 3.0<|vz|<15.", "v_{2}{6}/v_{2}{4} |vz|<15.", "v_{2}{6}/v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV286", "comp_pPb_vz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3.0", "v_{2}{8}/v_{2}{6} 3.0<|vz|<15.", "v_{2}{8}/v_{2}{6} |vz|<15.", "v_{2}{8}/v_{2}{6}", 0.02)'


############ PbPb tracking
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grV24",  "comp_PbPb_trk_v24.pdf", "v_{2}{4} Tight",          "v_{2}{4} Loose",                   "v_{2}{4} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV3PbPb_sysTight_GMO.root", "grV3PbPb_sysLoosePt01_GMO.root", "grV3PbPb_GMO.root",  "grV34",  "comp_PbPb_trk_v34.pdf", "v_{3}{4} Tight",          "v_{3}{4} Loose",                   "v_{3}{4} standard",          "v_{3}{4}", 0.02)'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grV26",  "comp_PbPb_trk_v26.pdf", "v_{2}{6} Tight",          "v_{2}{6} Loose",                   "v_{2}{6} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grV28",  "comp_PbPb_trk_v28.pdf", "v_{2}{8} Tight",          "v_{2}{8} Loose",                   "v_{2}{8} standard",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root", "grV264", "comp_PbPb_trk_v264.pdf", "v_{2}{6}/v_{2}{4} Tight", "v_{2}{6}/v_{2}{4} Loose", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root", "grV286", "comp_PbPb_trk_v286.pdf", "v_{2}{8}/v_{2}{6} Tight", "v_{2}{8}/v_{2}{6} Loose", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}", 0.01)'


############## PbPb vertex
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV24",  "comp_PbPb_sysVz_v24.pdf",           "v_{2}{4} |vz|<3",          "v_{2}{4} 3<|vz|<15",          "v_{2}{4} |vz|<15",          "v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV26",  "comp_PbPb_sysVz_v26.pdf",           "v_{2}{6} |vz|<3",          "v_{2}{6} 3<|vz|<15",          "v_{2}{6} |vz|<15",          "v_{2}{6}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV28",  "comp_PbPb_sysVz_v28.pdf",           "v_{2}{8} |vz|<3",          "v_{2}{8} 3<|vz|<15",          "v_{2}{8} |vz|<15",          "v_{2}{8}", 0.01)'
root -l -b -q 'compare3.C("grV3PbPb_sysNarrow2.root", "grV3PbPb_sysWide2.root", "grV3PbPb_sysTight2.root", "grV34",  "comp_PbPb_sysVz_v34.pdf",           "v_{3}{4} |vz|<3",          "v_{3}{4} 3<|vz|<15",          "v_{3}{4} |vz|<15",          "v_{3}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV264", "comp_PbPb_sysVz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3", "v_{2}{6}/v_{2}{4} 3<|vz|<15", "v_{2}{6}/v_{2}{4} |vz|<15", "v_{2}{6}/v_{2}{4}", 0.01)'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV286", "comp_PbPb_sysVz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3", "v_{2}{8}/v_{2}{6} 3<|vz|<15", "v_{2}{8}/v_{2}{6} |vz|<15", "v_{2}{8}/v_{2}{6}", 0.01)'

################### PhiAcc
#root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV24",  "comp_pPb_sysPhiAcc_v24.pdf",  " ",          "v_{2}{4} #phi acc",          "v_{2}{4}",          "v_{2}{4}")'
#root -l -b -q 'compare3.C("grV3_sysPhiAcc.root", "grV3_sysPhiAcc.root", "grV3_merged.root", "grC34",  "comp_pPb_sysPhiAcc_c34.pdf",  " ",          "v_{3}{4} #phi acc",          "v_{3}{4}",          "v_{3}{4}")'
#root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV26",  "comp_pPb_sysPhiAcc_v26.pdf",  " ",          "v_{2}{6} #phi acc",          "v_{2}{6}",          "v_{2}{6}")'
#root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV28",  "comp_pPb_sysPhiAcc_v28.pdf",  " ",          "v_{2}{8} #phi acc",          "v_{2}{8}",          "v_{2}{8}")'
#root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV264", "comp_pPb_sysPhiAcc_v264.pdf", " ", "v_{2}{6}/v_{2}{4} #phi acc", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV286", "comp_pPb_sysPhiAcc_v286.pdf", " ", "v_{2}{8}/v_{2}{6} #phi acc", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'

root -l -b -q 'compare3.C("grV3_sysPhiAcc.root", "grV3_sysPhiAcc.root", "grV3_merged.root", "grV34",  "comp_pPb_sysPhiAcc_v34.pdf",  " ",          "v_{3}{4} #phi acc",          "v_{3}{4}",          "v_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV24",  "comp_pPb_sysPhiAcc_v24.pdf",  " ",          "v_{2}{4} #phi acc",          "v_{2}{4}",          "v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV26",  "comp_pPb_sysPhiAcc_v26.pdf",  " ",          "v_{2}{6} #phi acc",          "v_{2}{6}",          "v_{2}{6}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV28",  "comp_pPb_sysPhiAcc_v28.pdf",  " ",          "v_{2}{8} #phi acc",          "v_{2}{8}",          "v_{2}{8}")'


################### PhiAcc PbPb
root -l -b -q 'compare3.C("grV2PbPb_sysPhiAcc.root", "grV2PbPb_sysPhiAcc.root", "grV2PbPb_GMO.root", "grV24", "comp_PbPb_sysPhiAcc_v24.pdf", " ", "v_{2}{4} #phi acc", "v_{2}{4}", "v_{2}{4}")'
root -l -b -q 'compare3.C("grV3PbPb_sysPhiAcc.root", "grV3PbPb_sysPhiAcc.root", "grV3PbPb_GMO.root", "grV34", "comp_PbPb_sysPhiAcc_v34.pdf", " ", "v_{3}{4} #phi acc", "v_{3}{4}", "v_{3}{4}")'

root -l -b -q 'compare3.C("grV2PbPb_sysPhiAcc.root", "grV2PbPb_sysPhiAcc.root", "grV2PbPb_GMO.root", "grV26", "comp_PbPb_sysPhiAcc_v26.pdf", " ", "v_{2}{6} #phi acc", "v_{2}{6}", "v_{2}{6}")'
root -l -b -q 'compare3.C("grV2PbPb_sysPhiAcc.root", "grV2PbPb_sysPhiAcc.root", "grV2PbPb_GMO.root", "grV28", "comp_PbPb_sysPhiAcc_v28.pdf", " ", "v_{2}{8} #phi acc", "v_{2}{8}", "v_{2}{8}")'










