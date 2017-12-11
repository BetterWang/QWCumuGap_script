################## Beam
root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC24",  "comp_pPb_sysBeam_c24.pdf",           "c_{2}{4} pPb",          "c_{2}{4} Pbp",          "c_{2}{4}",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grC34",  "comp_pPb_sysBeam_c34.pdf",           "c_{3}{4} pPb",          "c_{3}{4} Pbp",          "c_{3}{4}",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC26",  "comp_pPb_sysBeam_c26.pdf",           "c_{2}{6} pPb",          "c_{2}{6} Pbp",          "c_{2}{6}",          "c_{2}{6}")'
root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC28",  "comp_pPb_sysBeam_c28.pdf",           "c_{2}{8} pPb",          "c_{2}{8} Pbp",          "c_{2}{8}",          "c_{2}{8}")'
root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV264", "comp_pPb_sysBeam_v264.pdf", "v_{2}{6}/v_{2}{4} pPb", "v_{2}{6}/v_{2}{4} Pbp", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV286", "comp_pPb_sysBeam_v286.pdf", "v_{2}{8}/v_{2}{6} pPb", "v_{2}{8}/v_{2}{6} Pbp", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'

############## PU
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grC24",  "comp_pPb_PU_c24.pdf", "c_{2}{4} HighPU",          "c_{2}{4} LowPU",                   "c_{2}{4} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root",  "grC34",  "comp_pPb_PU_c34.pdf", "c_{3}{4} HighPU",          "c_{3}{4} LowPU",                   "c_{3}{4} standard",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grC26",  "comp_pPb_PU_c26.pdf", "c_{2}{6} HighPU",          "c_{2}{6} LowPU",                   "c_{2}{6} standard",          "c_{2}{6}")'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root",  "grC28",  "comp_pPb_PU_c28.pdf", "c_{2}{8} HighPU",          "c_{2}{8} LowPU",                   "c_{2}{8} standard",          "c_{2}{8}")'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV264", "comp_pPb_PU_v264.pdf", "v_{2}{6}/v_{2}{4} HighPU", "v_{2}{6}/v_{2}{4} LowPU", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV286", "comp_pPb_PU_v286.pdf", "v_{2}{8}/v_{2}{6} HighPU", "v_{2}{8}/v_{2}{6} LowPU", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}")'

################ HLT
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grC24",  "comp_pPb_HLT_c24.pdf", " ",          "c_{2}{4} HLT",                   "c_{2}{4} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root",  "grC34",  "comp_pPb_HLT_c34.pdf", " ",          "c_{3}{4} HLT",                   "c_{3}{4} standard",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grC26",  "comp_pPb_HLT_c26.pdf", " ",          "c_{2}{6} HLT",                   "c_{2}{6} standard",          "c_{2}{6}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root",  "grC28",  "comp_pPb_HLT_c28.pdf", " ",          "c_{2}{8} HLT",                   "c_{2}{8} standard",          "c_{2}{8}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV264", "comp_pPb_HLT_v264.pdf", " ", "v_{2}{6}/v_{2}{4} HLT", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV286", "comp_pPb_HLT_v286.pdf", " ", "v_{2}{8}/v_{2}{6} HLT", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}")'

############### tracking
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grC24",  "comp_pPb_trk_c24.pdf", "c_{2}{4} Tight",          "c_{2}{4} Loose",                   "c_{2}{4} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root",  "grC34",  "comp_pPb_trk_c34.pdf", "c_{3}{4} Tight",          "c_{3}{4} Loose",                   "c_{3}{4} standard",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grC26",  "comp_pPb_trk_c26.pdf", "c_{2}{6} Tight",          "c_{2}{6} Loose",                   "c_{2}{6} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root",  "grC28",  "comp_pPb_trk_c28.pdf", "c_{2}{8} Tight",          "c_{2}{8} Loose",                   "c_{2}{8} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV264", "comp_pPb_trk_v264.pdf", "v_{2}{6}/v_{2}{4} Tight", "v_{2}{6}/v_{2}{4} Loose", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV286", "comp_pPb_trk_v286.pdf", "v_{2}{8}/v_{2}{6} Tight", "v_{2}{8}/v_{2}{6} Loose", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}")'


############### vertex
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grC24", "comp_pPb_vz_c24.pdf",           "c_{2}{4} |vz|<3.0",          "c_{2}{4} 3.0<|vz|<15.",          "c_{2}{4} |vz|<15.",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root",  "grC34", "comp_pPb_vz_c34.pdf",           "c_{3}{4} |vz|<3.0",          "c_{3}{4} 3.0<|vz|<15.",          "c_{3}{4} |vz|<15.",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grC26", "comp_pPb_vz_c26.pdf",           "c_{2}{6} |vz|<3.0",          "c_{2}{6} 3.0<|vz|<15.",          "c_{2}{6} |vz|<15.",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root",  "grC28", "comp_pPb_vz_c28.pdf",           "c_{2}{8} |vz|<3.0",          "c_{2}{8} 3.0<|vz|<15.",          "c_{2}{8} |vz|<15.",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV264", "comp_pPb_vz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3.0", "v_{2}{6}/v_{2}{4} 3.0<|vz|<15.", "v_{2}{6}/v_{2}{4} |vz|<15.", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV286", "comp_pPb_vz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3.0", "v_{2}{8}/v_{2}{6} 3.0<|vz|<15.", "v_{2}{8}/v_{2}{6} |vz|<15.", "v_{2}{8}/v_{2}{6}")'


############ PbPb tracking
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grC24",  "comp_PbPb_trk_c24.pdf", "c_{2}{4} Tight",          "c_{2}{4} Loose",                   "c_{2}{4} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3PbPb_sysTight_GMO.root", "grV3PbPb_sysLoosePt01_GMO.root", "grV3PbPb_GMO.root",  "grC34",  "comp_PbPb_trk_c34.pdf", "c_{3}{4} Tight",          "c_{3}{4} Loose",                   "c_{3}{4} standard",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grC26",  "comp_PbPb_trk_c26.pdf", "c_{2}{6} Tight",          "c_{2}{6} Loose",                   "c_{2}{6} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root",  "grC28",  "comp_PbPb_trk_c28.pdf", "c_{2}{8} Tight",          "c_{2}{8} Loose",                   "c_{2}{8} standard",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root", "grV264", "comp_PbPb_trk_v264.pdf", "v_{2}{6}/v_{2}{4} Tight", "v_{2}{6}/v_{2}{4} Loose", "v_{2}{6}/v_{2}{4} standard", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysTight_GMO.root", "grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_GMO.root", "grV286", "comp_PbPb_trk_v286.pdf", "v_{2}{8}/v_{2}{6} Tight", "v_{2}{8}/v_{2}{6} Loose", "v_{2}{8}/v_{2}{6} standard", "v_{2}{8}/v_{2}{6}")'


############## PbPb vertex
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC24",  "comp_PbPb_sysVz_c24.pdf",           "c_{2}{4} |vz|<3",          "c_{2}{4} 3<|vz|<15",          "c_{2}{4} |vz|<15",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC26",  "comp_PbPb_sysVz_c26.pdf",           "c_{2}{6} |vz|<3",          "c_{2}{6} 3<|vz|<15",          "c_{2}{6} |vz|<15",          "c_{2}{6}")'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC28",  "comp_PbPb_sysVz_c28.pdf",           "c_{2}{8} |vz|<3",          "c_{2}{8} 3<|vz|<15",          "c_{2}{8} |vz|<15",          "c_{2}{8}")'
root -l -b -q 'compare3.C("grV3PbPb_sysNarrow2.root", "grV3PbPb_sysWide2.root", "grV3PbPb_sysTight2.root", "grC34",  "comp_PbPb_sysVz_c34.pdf",           "c_{3}{4} |vz|<3",          "c_{3}{4} 3<|vz|<15",          "c_{3}{4} |vz|<15",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV264", "comp_PbPb_sysVz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3", "v_{2}{6}/v_{2}{4} 3<|vz|<15", "v_{2}{6}/v_{2}{4} |vz|<15", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV286", "comp_PbPb_sysVz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3", "v_{2}{8}/v_{2}{6} 3<|vz|<15", "v_{2}{8}/v_{2}{6} |vz|<15", "v_{2}{8}/v_{2}{6}")'

################## PhiAcc
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grC24",  "comp_pPb_sysPhiAcc_c24.pdf",  " ",          "c_{2}{4} #phi acc",          "c_{2}{4}",          "c_{2}{4}")'
root -l -b -q 'compare3.C("grV3_sysPhiAcc.root", "grV3_sysPhiAcc.root", "grV3_merged.root", "grC34",  "comp_pPb_sysPhiAcc_c34.pdf",  " ",          "c_{3}{4} #phi acc",          "c_{3}{4}",          "c_{3}{4}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grC26",  "comp_pPb_sysPhiAcc_c26.pdf",  " ",          "c_{2}{6} #phi acc",          "c_{2}{6}",          "c_{2}{6}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grC28",  "comp_pPb_sysPhiAcc_c28.pdf",  " ",          "c_{2}{8} #phi acc",          "c_{2}{8}",          "c_{2}{8}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV264", "comp_pPb_sysPhiAcc_v264.pdf", " ", "v_{2}{6}/v_{2}{4} #phi acc", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
root -l -b -q 'compare3.C("grV2_sysPhiAcc.root", "grV2_sysPhiAcc.root", "grV2_merged.root", "grV286", "comp_pPb_sysPhiAcc_v286.pdf", " ", "v_{2}{8}/v_{2}{6} #phi acc", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'



#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV24", "comp_pPb_v24.pdf", "v_{2}{4} pPb", "v_{2}{4} Pbp", "v_{2}{4} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV26", "comp_pPb_v26.pdf", "v_{2}{6} pPb", "v_{2}{6} Pbp", "v_{2}{6} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV28", "comp_pPb_v28.pdf", "v_{2}{8} pPb", "v_{2}{8} Pbp", "v_{2}{8} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC24", "comp_pPb_C24.pdf", "c_{2}{4} pPb", "c_{2}{4} Pbp", "c_{2}{4} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grV2n", "comp_pPb_v2n.pdf", "v_{2}{4} pPb 3-sub", "v_{2}{4} Pbp 3-sub", "v_{2}{4} pPb+Pbp 3-sub")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC2n", "comp_pPb_C2n.pdf", "c_{2}{4} pPb 3-sub", "c_{2}{4} Pbp 3-sub", "c_{2}{4} pPb+Pbp 3-sub")'

#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC24", "comp_pPb_C24.pdf", "c_{2}{4} pPb", "c_{2}{4} Pbp", "c_{2}{4} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC26", "comp_pPb_C26.pdf", "c_{2}{6} pPb", "c_{2}{6} Pbp", "c_{2}{6} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV2_pPb.root", "grV2_Pbp.root", "grV2_merged.root", "grC28", "comp_pPb_C28.pdf", "c_{2}{8} pPb", "c_{2}{8} Pbp", "c_{2}{8} pPb+Pbp")'
#
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grV34", "comp_pPb_v34.pdf", "v_{3}{4} pPb", "v_{3}{4} Pbp", "v_{3}{4} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grV36", "comp_pPb_v36.pdf", "v_{3}{6} pPb", "v_{3}{6} Pbp", "v_{3}{6} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grV38", "comp_pPb_v38.pdf", "v_{3}{8} pPb", "v_{3}{8} Pbp", "v_{3}{8} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grC34", "comp_pPb_C34.pdf", "c_{3}{4} pPb", "c_{3}{4} Pbp", "c_{3}{4} pPb+Pbp")'
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grV3n", "comp_pPb_v3n.pdf", "v_{3}{4} pPb 3-sub", "v_{3}{4} Pbp 3-sub", "v_{3}{4} pPb+Pbp 3-sub")'
#root -l -b -q 'compare3.C("grV3_pPb.root", "grV3_Pbp.root", "grV3_merged.root", "grC3n", "comp_pPb_C3n.pdf", "c_{3}{4} pPb 3-sub", "c_{3}{4} Pbp 3-sub", "c_{3}{4} pPb+Pbp 3-sub")'
#
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV24", "comp_pPb_track_v24.pdf", "v_{2}{4} Tight", "v_{2}{4} Loose", "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV26", "comp_pPb_track_v26.pdf", "v_{2}{6} Tight", "v_{2}{6} Loose", "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV28", "comp_pPb_track_v28.pdf", "v_{2}{8} Tight", "v_{2}{8} Loose", "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grC24", "comp_pPb_track_c24.pdf", "c_{2}{4} Tight", "c_{2}{4} Loose", "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grC26", "comp_pPb_track_c26.pdf", "c_{2}{6} Tight", "c_{2}{6} Loose", "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grC28", "comp_pPb_track_c28.pdf", "c_{2}{8} Tight", "c_{2}{8} Loose", "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grV2n", "comp_pPb_track_v2n.pdf", "v_{2}{4} Tight 3-sub", "v_{2}{4} Loose 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2_sysTight.root", "grV2_sysLoose.root", "grV2_merged.root", "grC2n", "comp_pPb_track_c2n.pdf", "c_{2}{4} Tight 3-sub", "c_{2}{4} Loose 3-sub", "c_{2}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grV34", "comp_pPb_track_v34.pdf", "v_{3}{4} Tight", "v_{3}{4} Loose", "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grV36", "comp_pPb_track_v36.pdf", "v_{3}{6} Tight", "v_{3}{6} Loose", "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grV38", "comp_pPb_track_v38.pdf", "v_{3}{8} Tight", "v_{3}{8} Loose", "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grC34", "comp_pPb_track_c34.pdf", "c_{3}{4} Tight", "c_{3}{4} Loose", "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grV3n", "comp_pPb_track_v3n.pdf", "v_{3}{4} Tight 3-sub", "v_{3}{4} Loose 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3_sysTight.root", "grV3_sysLoose.root", "grV3_merged.root", "grC3n", "comp_pPb_track_c3n.pdf", "c_{3}{4} Tight 3-sub", "c_{3}{4} Loose 3-sub", "c_{3}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV24", "comp_pPb_vz_v24.pdf", "v_{2}{4} |vz|<3.0", "v_{2}{4} 3.0<|vz|<15.", "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV26", "comp_pPb_vz_v26.pdf", "v_{2}{6} |vz|<3.0", "v_{2}{6} 3.0<|vz|<15.", "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV28", "comp_pPb_vz_v28.pdf", "v_{2}{8} |vz|<3.0", "v_{2}{8} 3.0<|vz|<15.", "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grC24", "comp_pPb_vz_c24.pdf", "c_{2}{4} |vz|<3.0", "c_{2}{4} 3.0<|vz|<15.", "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grV2n", "comp_pPb_vz_v2n.pdf", "v_{2}{4} |vz|<3.0 3-sub", "v_{2}{4} 3.0<|vz|<15 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grC2n", "comp_pPb_vz_c2n.pdf", "c_{2}{4} |vz|<3.0 3-sub", "c_{2}{4} 3.0<|vz|<15 3-sub", "c_{2}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grC26", "comp_pPb_vz_c26.pdf", "c_{2}{6} |vz|<3.0", "c_{2}{6} 3.0<|vz|<15.", "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysNarrow.root", "grV2_sysWide.root", "grV2_merged.root", "grC28", "comp_pPb_vz_c28.pdf", "c_{2}{8} |vz|<3.0", "c_{2}{8} 3.0<|vz|<15.", "c_{2}{8} standard")'

#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grV34", "comp_pPb_vz_v34.pdf", "v_{3}{4} |vz|<3.0", "v_{3}{4} 3.0<|vz|<15.", "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grV36", "comp_pPb_vz_v36.pdf", "v_{3}{6} |vz|<3.0", "v_{3}{6} 3.0<|vz|<15.", "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grV38", "comp_pPb_vz_v38.pdf", "v_{3}{8} |vz|<3.0", "v_{3}{8} 3.0<|vz|<15.", "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grC34", "comp_pPb_vz_c34.pdf", "c_{3}{4} |vz|<3.0", "c_{3}{4} 3.0<|vz|<15.", "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grV3n", "comp_pPb_vz_v3n.pdf", "v_{3}{4} |vz|<3.0 3-sub", "v_{3}{4} 3.0<|vz|<15 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3_sysNarrow.root", "grV3_sysWide.root", "grV3_merged.root", "grC3n", "comp_pPb_vz_c3n.pdf", "c_{3}{4} |vz|<3.0 3-sub", "c_{3}{4} 3.0<|vz|<15 3-sub", "c_{3}{4} standard 3-sub")'


#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV24", "comp_PbPb_trackPx_v24.pdf", "v_{2}{4} Tight",       "v_{2}{4} PxLayer1",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV26", "comp_PbPb_trackPx_v26.pdf", "v_{2}{6} Tight",       "v_{2}{6} PxLayer1",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV28", "comp_PbPb_trackPx_v28.pdf", "v_{2}{8} Tight",       "v_{2}{8} PxLayer1",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC24", "comp_PbPb_trackPx_c24.pdf", "c_{2}{4} Tight",       "c_{2}{4} PxLayer1",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC26", "comp_PbPb_trackPx_c26.pdf", "c_{2}{6} Tight",       "c_{2}{6} PxLayer1",       "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC28", "comp_PbPb_trackPx_c28.pdf", "c_{2}{8} Tight",       "c_{2}{8} PxLayer1",       "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV2n", "comp_PbPb_trackPx_v2n.pdf", "v_{2}{4} Tight 3-sub", "v_{2}{4} PxLayer1 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC2n", "comp_PbPb_trackPx_c2n.pdf", "c_{2}{4} Tight 3-sub", "c_{2}{4} PxLayer1 3-sub", "c_{2}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grV24", "comp_PbPb_track_v24.pdf", "v_{2}{4} Tight",       "v_{2}{4} Loose",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grV26", "comp_PbPb_track_v26.pdf", "v_{2}{6} Tight",       "v_{2}{6} Loose",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grV28", "comp_PbPb_track_v28.pdf", "v_{2}{8} Tight",       "v_{2}{8} Loose",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grC24", "comp_PbPb_track_c24.pdf", "c_{2}{4} Tight",       "c_{2}{4} Loose",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grC26", "comp_PbPb_track_c26.pdf", "c_{2}{6} Tight",       "c_{2}{6} Loose",       "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grC28", "comp_PbPb_track_c28.pdf", "c_{2}{8} Tight",       "c_{2}{8} Loose",       "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grV2n", "comp_PbPb_track_v2n.pdf", "v_{2}{4} Tight 3-sub", "v_{2}{4} Loose 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight.root", "grV2PbPb_sysLoose.root", "grV2PbPb.root", "grC2n", "comp_PbPb_track_c2n.pdf", "c_{2}{4} Tight 3-sub", "c_{2}{4} Loose 3-sub", "c_{2}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grV34", "comp_PbPb_track_v34.pdf", "v_{3}{4} Tight",       "v_{3}{4} Loose",       "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grV36", "comp_PbPb_track_v36.pdf", "v_{3}{6} Tight",       "v_{3}{6} Loose",       "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grV38", "comp_PbPb_track_v38.pdf", "v_{3}{8} Tight",       "v_{3}{8} Loose",       "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grC34", "comp_PbPb_track_c34.pdf", "c_{3}{4} Tight",       "c_{3}{4} Loose",       "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grV3n", "comp_PbPb_track_v3n.pdf", "v_{3}{4} Tight 3-sub", "v_{3}{4} Loose 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight.root", "grV3PbPb_sysLoose.root", "grV3PbPb.root", "grC3n", "comp_PbPb_track_c3n.pdf", "c_{3}{4} Tight 3-sub", "c_{3}{4} Loose 3-sub", "c_{3}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grV24", "comp_PbPb_vz_v24.pdf", "v_{2}{4} |vz|<3.0",       "v_{2}{4} 3.0<|vz|<15.",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grV26", "comp_PbPb_vz_v26.pdf", "v_{2}{6} |vz|<3.0",       "v_{2}{6} 3.0<|vz|<15.",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grV28", "comp_PbPb_vz_v28.pdf", "v_{2}{8} |vz|<3.0",       "v_{2}{8} 3.0<|vz|<15.",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grC24", "comp_PbPb_vz_c24.pdf", "c_{2}{4} |vz|<3.0",       "c_{2}{4} 3.0<|vz|<15.",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grV2n", "comp_PbPb_vz_v2n.pdf", "v_{2}{4} |vz|<3.0 3-sub", "v_{2}{4} 3.0<|vz|<15. 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow.root", "grV2PbPb_sysWide.root", "grV2PbPb.root", "grC2n", "comp_PbPb_vz_c2n.pdf", "c_{2}{4} |vz|<3.0 3-sub", "c_{2}{4} 3.0<|vz|<15. 3-sub", "c_{2}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grV34", "comp_PbPb_vz_v34.pdf", "v_{3}{4} |vz|<3.0",       "v_{3}{4} 3.0<|vz|<15.",       "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grV36", "comp_PbPb_vz_v36.pdf", "v_{3}{6} |vz|<3.0",       "v_{3}{6} 3.0<|vz|<15.",       "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grV38", "comp_PbPb_vz_v38.pdf", "v_{3}{8} |vz|<3.0",       "v_{3}{8} 3.0<|vz|<15.",       "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grC34", "comp_PbPb_vz_c34.pdf", "c_{3}{4} |vz|<3.0",       "c_{3}{4} 3.0<|vz|<15.",       "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grV3n", "comp_PbPb_vz_v3n.pdf", "v_{3}{4} |vz|<3.0 3-sub", "v_{3}{4} 3.0<|vz|<15. 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow.root", "grV3PbPb_sysWide.root", "grV3PbPb.root", "grC3n", "comp_PbPb_vz_c3n.pdf", "c_{3}{4} |vz|<3.0 3-sub", "c_{3}{4} 3.0<|vz|<15. 3-sub", "c_{3}{4} standard 3-sub")'


#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV24", "comp_pPb_PU_v24.pdf", "v_{2}{4} HighPU",       "v_{2}{4} LowPU",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV26", "comp_pPb_PU_v26.pdf", "v_{2}{6} HighPU",       "v_{2}{6} LowPU",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV28", "comp_pPb_PU_v28.pdf", "v_{2}{8} HighPU",       "v_{2}{8} LowPU",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grC24", "comp_pPb_PU_c24.pdf", "c_{2}{4} HighPU",       "c_{2}{4} LowPU",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grV2n", "comp_pPb_PU_v2n.pdf", "v_{2}{4} HighPU 3-sub", "v_{2}{4} LowPU 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2_sysHighPU.root", "grV2_sysLowPU.root", "grV2_merged.root", "grC2n", "comp_pPb_PU_c2n.pdf", "c_{2}{4} HighPU 3-sub", "c_{2}{4} LowPU 3-sub", "c_{2}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grV34", "comp_pPb_PU_v34.pdf", "v_{3}{4} HighPU",       "v_{3}{4} LowPU",       "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grV36", "comp_pPb_PU_v36.pdf", "v_{3}{6} HighPU",       "v_{3}{6} LowPU",       "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grV38", "comp_pPb_PU_v38.pdf", "v_{3}{8} HighPU",       "v_{3}{8} LowPU",       "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grC34", "comp_pPb_PU_c34.pdf", "c_{3}{4} HighPU",       "c_{3}{4} LowPU",       "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grV3n", "comp_pPb_PU_v3n.pdf", "v_{3}{4} HighPU 3-sub", "v_{3}{4} LowPU 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3_sysHighPU.root", "grV3_sysLowPU.root", "grV3_merged.root", "grC3n", "comp_pPb_PU_c3n.pdf", "c_{3}{4} HighPU 3-sub", "c_{3}{4} LowPU 3-sub", "c_{3}{4} standard 3-sub")'
#

#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV24", "comp_pPb_HLT_v24.pdf", "v_{2}{4} HLT",       "v_{2}{4} HLT",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV26", "comp_pPb_HLT_v26.pdf", "v_{2}{6} HLT",       "v_{2}{6} HLT",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV28", "comp_pPb_HLT_v28.pdf", "v_{2}{8} HLT",       "v_{2}{8} HLT",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grC24", "comp_pPb_HLT_c24.pdf", "c_{2}{4} HLT",       "c_{2}{4} HLT",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grV2n", "comp_pPb_HLT_v2n.pdf", "v_{2}{4} HLT 3-sub", "v_{2}{4} HLT 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2_sysHLT.root", "grV2_sysHLT.root", "grV2_merged.root", "grC2n", "comp_pPb_HLT_c2n.pdf", "c_{2}{4} HLT 3-sub", "c_{2}{4} HLT 3-sub", "c_{2}{4} standard 3-sub")'
#
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grV34", "comp_pPb_HLT_v34.pdf", "v_{3}{4} HLT",       "v_{3}{4} HLT",       "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grV36", "comp_pPb_HLT_v36.pdf", "v_{3}{6} HLT",       "v_{3}{6} HLT",       "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grV38", "comp_pPb_HLT_v38.pdf", "v_{3}{8} HLT",       "v_{3}{8} HLT",       "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grC34", "comp_pPb_HLT_c34.pdf", "c_{3}{4} HLT",       "c_{3}{4} HLT",       "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grV3n", "comp_pPb_HLT_v3n.pdf", "v_{3}{4} HLT 3-sub", "v_{3}{4} HLT 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3_sysHLT.root", "grV3_sysHLT.root", "grV3_merged.root", "grC3n", "comp_pPb_HLT_c3n.pdf", "c_{3}{4} HLT 3-sub", "c_{3}{4} HLT 3-sub", "c_{3}{4} standard 3-sub")'
#


#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grV24", "comp_pPb_sysEff_v24.pdf", "v_{2}{4} sysEff",       "v_{2}{4} sysEff",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grV26", "comp_pPb_sysEff_v26.pdf", "v_{2}{6} sysEff",       "v_{2}{6} sysEff",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grV28", "comp_pPb_sysEff_v28.pdf", "v_{2}{8} sysEff",       "v_{2}{8} sysEff",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grC24", "comp_pPb_sysEff_c24.pdf", "c_{2}{4} sysEff",       "c_{2}{4} sysEff",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grV2n", "comp_pPb_sysEff_v2n.pdf", "v_{2}{4} sysEff 3-sub", "v_{2}{4} sysEff 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2_sysEff.root", "grV2_sysEff.root", "grV2_merged.root", "grC2n", "comp_pPb_sysEff_c2n.pdf", "c_{2}{4} sysEff 3-sub", "c_{2}{4} sysEff 3-sub", "c_{2}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grV34", "comp_pPb_sysEff_v34.pdf", "v_{3}{4} sysEff",       "v_{3}{4} sysEff",       "v_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grV36", "comp_pPb_sysEff_v36.pdf", "v_{3}{6} sysEff",       "v_{3}{6} sysEff",       "v_{3}{6} standard")'
#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grV38", "comp_pPb_sysEff_v38.pdf", "v_{3}{8} sysEff",       "v_{3}{8} sysEff",       "v_{3}{8} standard")'
#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grC34", "comp_pPb_sysEff_c34.pdf", "c_{3}{4} sysEff",       "c_{3}{4} sysEff",       "c_{3}{4} standard")'
#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grV3n", "comp_pPb_sysEff_v3n.pdf", "v_{3}{4} sysEff 3-sub", "v_{3}{4} sysEff 3-sub", "v_{3}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV3_sysEff.root", "grV3_sysEff.root", "grV3_merged.root", "grC3n", "comp_pPb_sysEff_c3n.pdf", "c_{3}{4} sysEff 3-sub", "c_{3}{4} sysEff 3-sub", "c_{3}{4} standard 3-sub")'



#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grV24", "comp_PbPb_track23_v24.pdf", "v_{2}{4} Tight2",       "v_{2}{4} Tight3",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grV26", "comp_PbPb_track23_v26.pdf", "v_{2}{6} Tight2",       "v_{2}{6} Tight3",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grV28", "comp_PbPb_track23_v28.pdf", "v_{2}{8} Tight2",       "v_{2}{8} Tight3",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grC24", "comp_PbPb_track23_c24.pdf", "c_{2}{4} Tight2",       "c_{2}{4} Tight3",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grC26", "comp_PbPb_track23_c26.pdf", "c_{2}{6} Tight2",       "c_{2}{6} Tight3",       "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grC28", "comp_PbPb_track23_c28.pdf", "c_{2}{8} Tight2",       "c_{2}{8} Tight3",       "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grV2n", "comp_PbPb_track23_v2n.pdf", "v_{2}{4} Tight2 3-sub", "v_{2}{4} Tight3 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTight3.root", "grV2PbPb.root", "grC2n", "comp_PbPb_track23_c2n.pdf", "c_{2}{4} Tight2 3-sub", "c_{2}{4} Tight3 3-sub", "c_{2}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grV24", "comp_PbPb_track2er_v24.pdf", "v_{2}{4} Tight2",       "v_{2}{4} Tighter",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grV26", "comp_PbPb_track2er_v26.pdf", "v_{2}{6} Tight2",       "v_{2}{6} Tighter",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grV28", "comp_PbPb_track2er_v28.pdf", "v_{2}{8} Tight2",       "v_{2}{8} Tighter",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grC24", "comp_PbPb_track2er_c24.pdf", "c_{2}{4} Tight2",       "c_{2}{4} Tighter",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grC26", "comp_PbPb_track2er_c26.pdf", "c_{2}{6} Tight2",       "c_{2}{6} Tighter",       "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grC28", "comp_PbPb_track2er_c28.pdf", "c_{2}{8} Tight2",       "c_{2}{8} Tighter",       "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grV2n", "comp_PbPb_track2er_v2n.pdf", "v_{2}{4} Tight2 3-sub", "v_{2}{4} Tighter 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb.root", "grC2n", "comp_PbPb_track2er_c2n.pdf", "c_{2}{4} Tight2 3-sub", "c_{2}{4} Tighter 3-sub", "c_{2}{4} standard 3-sub")'





#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV24", "comp_PbPb_trackPx_v24.pdf", "v_{2}{4} std",       "v_{2}{4} PxLayer1",       "v_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV26", "comp_PbPb_trackPx_v26.pdf", "v_{2}{6} std",       "v_{2}{6} PxLayer1",       "v_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV28", "comp_PbPb_trackPx_v28.pdf", "v_{2}{8} std",       "v_{2}{8} PxLayer1",       "v_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC24", "comp_PbPb_trackPx_c24.pdf", "c_{2}{4} std",       "c_{2}{4} PxLayer1",       "c_{2}{4} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC26", "comp_PbPb_trackPx_c26.pdf", "c_{2}{6} std",       "c_{2}{6} PxLayer1",       "c_{2}{6} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC28", "comp_PbPb_trackPx_c28.pdf", "c_{2}{8} std",       "c_{2}{8} PxLayer1",       "c_{2}{8} standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grV2n", "comp_PbPb_trackPx_v2n.pdf", "v_{2}{4} std 3-sub", "v_{2}{4} PxLayer1 3-sub", "v_{2}{4} standard 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysStd.root", "grV2PbPb_sysPxLayer1.root", "grV2PbPb.root", "grC2n", "comp_PbPb_trackPx_c2n.pdf", "c_{2}{4} std 3-sub", "c_{2}{4} PxLayer1 3-sub", "c_{2}{4} standard 3-sub")'

#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grV24", "comp_PbPb_trackTight2er_v24.pdf", "v_{2}{4} Tight2",       "v_{2}{4} Tighter",       "v_{2}{4} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grV26", "comp_PbPb_trackTight2er_v26.pdf", "v_{2}{6} Tight2",       "v_{2}{6} Tighter",       "v_{2}{6} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grV28", "comp_PbPb_trackTight2er_v28.pdf", "v_{2}{8} Tight2",       "v_{2}{8} Tighter",       "v_{2}{8} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grC24", "comp_PbPb_trackTight2er_c24.pdf", "c_{2}{4} Tight2",       "c_{2}{4} Tighter",       "c_{2}{4} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grC26", "comp_PbPb_trackTight2er_c26.pdf", "c_{2}{6} Tight2",       "c_{2}{6} Tighter",       "c_{2}{6} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grC28", "comp_PbPb_trackTight2er_c28.pdf", "c_{2}{8} Tight2",       "c_{2}{8} Tighter",       "c_{2}{8} Tight")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grV2n", "comp_PbPb_trackTight2er_v2n.pdf", "v_{2}{4} Tight2 3-sub", "v_{2}{4} Tighter 3-sub", "v_{2}{4} Tight 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight.root", "grC2n", "comp_PbPb_trackTight2er_c2n.pdf", "c_{2}{4} Tight2 3-sub", "c_{2}{4} Tighter 3-sub", "c_{2}{4} Tight 3-sub")'



#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grV24", "comp_PbPb_trackTight2xyz_v24.pdf", "v_{2}{4} Tight2dxy",       "v_{2}{4} Tight2dz",       "v_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grV26", "comp_PbPb_trackTight2xyz_v26.pdf", "v_{2}{6} Tight2dxy",       "v_{2}{6} Tight2dz",       "v_{2}{6} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grV28", "comp_PbPb_trackTight2xyz_v28.pdf", "v_{2}{8} Tight2dxy",       "v_{2}{8} Tight2dz",       "v_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grC24", "comp_PbPb_trackTight2xyz_c24.pdf", "c_{2}{4} Tight2dxy",       "c_{2}{4} Tight2dz",       "c_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grC26", "comp_PbPb_trackTight2xyz_c26.pdf", "c_{2}{6} Tight2dxy",       "c_{2}{6} Tight2dz",       "c_{2}{6} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grC28", "comp_PbPb_trackTight2xyz_c28.pdf", "c_{2}{8} Tight2dxy",       "c_{2}{8} Tight2dz",       "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grV2n", "comp_PbPb_trackTight2xyz_v2n.pdf", "v_{2}{4} Tight2dxy 3-sub", "v_{2}{4} Tight2dz 3-sub", "v_{2}{4} Tight2 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2dxy.root", "grV2PbPb_sysTight2dz.root", "grV2PbPb_sysTight2.root", "grC2n", "comp_PbPb_trackTight2xyz_c2n.pdf", "c_{2}{4} Tight2dxy 3-sub", "c_{2}{4} Tight2dz 3-sub", "c_{2}{4} Tight2 3-sub")'



#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grV24", "comp_PbPb_eta_v24.pdf", "v_{2}{4} 0<#eta<2.4",       "v_{2}{4} -2.4<#eta<0",       "v_{2}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grV26", "comp_PbPb_eta_v26.pdf", "v_{2}{6} 0<#eta<2.4",       "v_{2}{6} -2.4<#eta<0",       "v_{2}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grV28", "comp_PbPb_eta_v28.pdf", "v_{2}{8} 0<#eta<2.4",       "v_{2}{8} -2.4<#eta<0",       "v_{2}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grC24", "comp_PbPb_eta_c24.pdf", "c_{2}{4} 0<#eta<2.4",       "c_{2}{4} -2.4<#eta<0",       "c_{2}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grC26", "comp_PbPb_eta_c26.pdf", "c_{2}{6} 0<#eta<2.4",       "c_{2}{6} -2.4<#eta<0",       "c_{2}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grC28", "comp_PbPb_eta_c28.pdf", "c_{2}{8} 0<#eta<2.4",       "c_{2}{8} -2.4<#eta<0",       "c_{2}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grV2n", "comp_PbPb_eta_v2n.pdf", "v_{2}{4} 0<#eta<2.4 3-sub", "v_{2}{4} -2.4<#eta<0 3-sub", "v_{2}{4} -2.4<#eta<2.4 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta.root", "grV2PbPb_sysTight2NegEta.root", "grV2PbPb_sysTight2.root", "grC2n", "comp_PbPb_eta_c2n.pdf", "c_{2}{4} 0<#eta<2.4 3-sub", "c_{2}{4} -2.4<#eta<0 3-sub", "c_{2}{4} -2.4<#eta<2.4 3-sub")'
#

#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grV34", "comp_PbPb_eta_v34.pdf", "v_{3}{4} 0<#eta<2.4",       "v_{3}{4} -2.4<#eta<0",       "v_{3}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grV36", "comp_PbPb_eta_v36.pdf", "v_{3}{6} 0<#eta<2.4",       "v_{3}{6} -2.4<#eta<0",       "v_{3}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grV38", "comp_PbPb_eta_v38.pdf", "v_{3}{8} 0<#eta<2.4",       "v_{3}{8} -2.4<#eta<0",       "v_{3}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grC34", "comp_PbPb_eta_c34.pdf", "c_{3}{4} 0<#eta<2.4",       "c_{3}{4} -2.4<#eta<0",       "c_{3}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grC36", "comp_PbPb_eta_c36.pdf", "c_{3}{6} 0<#eta<2.4",       "c_{3}{6} -2.4<#eta<0",       "c_{3}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grC38", "comp_PbPb_eta_c38.pdf", "c_{3}{8} 0<#eta<2.4",       "c_{3}{8} -2.4<#eta<0",       "c_{3}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grV3n", "comp_PbPb_eta_v3n.pdf", "v_{3}{4} 0<#eta<2.4 3-sub", "v_{3}{4} -2.4<#eta<0 3-sub", "v_{3}{4} -2.4<#eta<2.4 3-sub")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta.root", "grV3PbPb_sysTight2NegEta.root", "grV3PbPb_sysTight2.root", "grC3n", "comp_PbPb_eta_c3n.pdf", "c_{3}{4} 0<#eta<2.4 3-sub", "c_{3}{4} -2.4<#eta<0 3-sub", "c_{3}{4} -2.4<#eta<2.4 3-sub")'


#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grV24", "comp_PbPb_eta2_v24.pdf", "v_{2}{4} 0<#eta<2.4",       "v_{2}{4} -2.4<#eta<0",       "v_{2}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grV26", "comp_PbPb_eta2_v26.pdf", "v_{2}{6} 0<#eta<2.4",       "v_{2}{6} -2.4<#eta<0",       "v_{2}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grV28", "comp_PbPb_eta2_v28.pdf", "v_{2}{8} 0<#eta<2.4",       "v_{2}{8} -2.4<#eta<0",       "v_{2}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grC24", "comp_PbPb_eta2_c24.pdf", "c_{2}{4} 0<#eta<2.4",       "c_{2}{4} -2.4<#eta<0",       "c_{2}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grC26", "comp_PbPb_eta2_c26.pdf", "c_{2}{6} 0<#eta<2.4",       "c_{2}{6} -2.4<#eta<0",       "c_{2}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grC28", "comp_PbPb_eta2_c28.pdf", "c_{2}{8} 0<#eta<2.4",       "c_{2}{8} -2.4<#eta<0",       "c_{2}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grV2n", "comp_PbPb_eta2_v2n.pdf", "v_{2}{4} 0<#eta<2.4 3-sub", "v_{2}{4} -2.4<#eta<0 3-sub", "v_{2}{4} -2.4<#eta<2.4 3-sub")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2PosEta2.root", "grV2PbPb_sysTight2NegEta2.root", "grV2PbPb_sysTight2.root", "grC2n", "comp_PbPb_eta2_c2n.pdf", "c_{2}{4} 0<#eta<2.4 3-sub", "c_{2}{4} -2.4<#eta<0 3-sub", "c_{2}{4} -2.4<#eta<2.4 3-sub")'
#
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grV34", "comp_PbPb_eta2_v34.pdf", "v_{3}{4} 0<#eta<2.4",       "v_{3}{4} -2.4<#eta<0",       "v_{3}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grV36", "comp_PbPb_eta2_v36.pdf", "v_{3}{6} 0<#eta<2.4",       "v_{3}{6} -2.4<#eta<0",       "v_{3}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grV38", "comp_PbPb_eta2_v38.pdf", "v_{3}{8} 0<#eta<2.4",       "v_{3}{8} -2.4<#eta<0",       "v_{3}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grC34", "comp_PbPb_eta2_c34.pdf", "c_{3}{4} 0<#eta<2.4",       "c_{3}{4} -2.4<#eta<0",       "c_{3}{4} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grC36", "comp_PbPb_eta2_c36.pdf", "c_{3}{6} 0<#eta<2.4",       "c_{3}{6} -2.4<#eta<0",       "c_{3}{6} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grC38", "comp_PbPb_eta2_c38.pdf", "c_{3}{8} 0<#eta<2.4",       "c_{3}{8} -2.4<#eta<0",       "c_{3}{8} -2.4<#eta<2.4")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grV3n", "comp_PbPb_eta2_v3n.pdf", "v_{3}{4} 0<#eta<2.4 3-sub", "v_{3}{4} -2.4<#eta<0 3-sub", "v_{3}{4} -2.4<#eta<2.4 3-sub")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight2PosEta2.root", "grV3PbPb_sysTight2NegEta2.root", "grV3PbPb_sysTight2.root", "grC3n", "comp_PbPb_eta2_c3n.pdf", "c_{3}{4} 0<#eta<2.4 3-sub", "c_{3}{4} -2.4<#eta<0 3-sub", "c_{3}{4} -2.4<#eta<2.4 3-sub")'


#root -l -b -q 'compare3.C("grV2PbPb_sysTightEta1.root", "grV2PbPb_sysLooseEta1.root", "grV2PbPb_Eta1.root", "grC24", "comp_PbPb_trackEta1_v24.pdf", "c_{2}{4} |#eta|<1 Tight",       "c_{2}{4} |#eta|<1 Loose",       "c_{2}{4} |#eta|<1 standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTightEta1.root", "grV2PbPb_sysLooseEta1.root", "grV2PbPb_Eta1.root", "grC26", "comp_PbPb_trackEta1_v26.pdf", "c_{2}{6} |#eta|<1 Tight",       "c_{2}{6} |#eta|<1 Loose",       "c_{2}{6} |#eta|<1 standard")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTightEta1.root", "grV2PbPb_sysLooseEta1.root", "grV2PbPb_Eta1.root", "grC28", "comp_PbPb_trackEta1_v28.pdf", "c_{2}{8} |#eta|<1 Tight",       "c_{2}{8} |#eta|<1 Loose",       "c_{2}{8} |#eta|<1 standard")'



#root -l -b -q 'compare3.C("grV2PbPb_sysLooseXTight2.root", "grV2PbPb_sysLooseXstd.root", "grV2PbPb_sysLoose.root", "grC24", "comp_PbPb_trackLoose_c24.pdf", "c_{2}{4} LooseXTight2",       "c_{2}{4} LooseXstd",       "c_{2}{4} Loose")'
#root -l -b -q 'compare3.C("grV2PbPb_sysLooseXTight2.root", "grV2PbPb_sysLooseXstd.root", "grV2PbPb_sysLoose.root", "grC26", "comp_PbPb_trackLoose_c26.pdf", "c_{2}{4} LooseXTight2",       "c_{2}{6} LooseXstd",       "c_{2}{8} Loose")'
#root -l -b -q 'compare3.C("grV2PbPb_sysLooseXTight2.root", "grV2PbPb_sysLooseXstd.root", "grV2PbPb_sysLoose.root", "grC28", "comp_PbPb_trackLoose_c28.pdf", "c_{2}{4} LooseXTight2",       "c_{2}{8} LooseXstd",       "c_{2}{8} Loose")'

#root -l -b -q 'compare3.C("grV2PbPb_sysTight2XLoose.root", "grV2PbPb_sysTight2Xstd.root", "grV2PbPb_sysTight2.root", "grC24", "comp_PbPb_trackTight2_c24.pdf", "c_{2}{4} Tight2XLoose",    "c_{2}{4} Tight2Xstd",     "c_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2XLoose.root", "grV2PbPb_sysTight2Xstd.root", "grV2PbPb_sysTight2.root", "grC26", "comp_PbPb_trackTight2_c26.pdf", "c_{2}{4} Tight2XLoose",    "c_{2}{6} Tight2Xstd",     "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight2XLoose.root", "grV2PbPb_sysTight2Xstd.root", "grV2PbPb_sysTight2.root", "grC28", "comp_PbPb_trackTight2_c28.pdf", "c_{2}{4} Tight2XLoose",    "c_{2}{8} Tight2Xstd",     "c_{2}{8} Tight2")'









#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTight.root", "grV2_sysTight2.root", "grC24", "comp_pPb_sysTrack2_c24.pdf", "c_{2}{4} Standard",    "c_{2}{4} Tight",     "c_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTight.root", "grV2_sysTight2.root", "grC26", "comp_pPb_sysTrack2_c26.pdf", "c_{2}{6} Standard",    "c_{2}{6} Tight",     "c_{2}{6} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTight.root", "grV2_sysTight2.root", "grC28", "comp_pPb_sysTrack2_c28.pdf", "c_{2}{8} Standard",    "c_{2}{8} Tight",     "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV3_merged.root", "grV3_sysTight.root", "grV3_sysTight2.root", "grC34", "comp_pPb_sysTrack2_c34.pdf", "c_{3}{4} Standard",    "c_{3}{4} Tight",     "c_{3}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTight.root", "grV2_sysTight2.root", "grV24", "comp_pPb_sysTrack2_v24.pdf", "v_{2}{4} Standard",    "v_{2}{4} Tight",     "v_{2}{4} Tight2")'


#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTighter.root", "grV2_sysTight2.root", "grC24", "comp_pPb_sysTrack2_c24.pdf", "c_{2}{4} Standard",    "c_{2}{4} Tighter",     "c_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTighter.root", "grV2_sysTight2.root", "grC26", "comp_pPb_sysTrack2_c26.pdf", "c_{2}{6} Standard",    "c_{2}{6} Tighter",     "c_{2}{6} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTighter.root", "grV2_sysTight2.root", "grC28", "comp_pPb_sysTrack2_c28.pdf", "c_{2}{8} Standard",    "c_{2}{8} Tighter",     "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV3_merged.root", "grV3_sysTighter.root", "grV3_sysTight2.root", "grC34", "comp_pPb_sysTrack2_c34.pdf", "c_{3}{4} Standard",    "c_{3}{4} Tighter",     "c_{3}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2_merged.root", "grV2_sysTighter.root", "grV2_sysTight2.root", "grV24", "comp_pPb_sysTrack2_v24.pdf", "v_{2}{4} Standard",    "v_{2}{4} Tighter",     "v_{2}{4} Tight2")'







#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC24", "comp_pPb_sysVz2_c24.pdf", "c_{2}{4} |vz|<3.0",    "c_{2}{4} 3.0<|vz|<15.",     "c_{2}{4} |vz|<15.")'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC26", "comp_pPb_sysVz2_c26.pdf", "c_{2}{6} |vz|<3.0",    "c_{2}{6} 3.0<|vz|<15.",     "c_{2}{6} |vz|<15.")'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC28", "comp_pPb_sysVz2_c28.pdf", "c_{2}{8} |vz|<3.0",    "c_{2}{8} 3.0<|vz|<15.",     "c_{2}{8} |vz|<15.")'
#root -l -b -q 'compare3.C("grV3_sysNarrow2.root", "grV3_sysWide2.root", "grV3_sysTight2.root", "grC34", "comp_pPb_sysVz2_c34.pdf", "c_{3}{4} |vz|<3.0",    "c_{3}{4} 3.0<|vz|<15.",     "c_{3}{4} |vz|<15.")'


#root -l -b -q 'compare3.C("grV2_sysTight4.root", "grV2_merged.root", "grV2_sysTight2.root", "grC24",  "comp_pPb_sysTrack_c24.pdf",  "c_{2}{4} tight",          "c_{2}{4} loose",          "c_{2}{4}"         , "c_{2}{4}"         )'
#root -l -b -q 'compare3.C("grV2_sysTight4.root", "grV2_merged.root", "grV2_sysTight2.root", "grC26",  "comp_pPb_sysTrack_c26.pdf",  "c_{2}{6} tight",          "c_{2}{6} loose",          "c_{2}{6}"         , "c_{2}{6}"         )'
#root -l -b -q 'compare3.C("grV2_sysTight4.root", "grV2_merged.root", "grV2_sysTight2.root", "grC28",  "comp_pPb_sysTrack_c28.pdf",  "c_{2}{8} tight",          "c_{2}{8} loose",          "c_{2}{8}"         , "c_{2}{8}"         )'
#root -l -b -q 'compare3.C("grV3_sysTight4.root", "grV3_merged.root", "grV3_sysTight2.root", "grC34",  "comp_pPb_sysTrack_c34.pdf",  "c_{3}{4} tight",          "c_{3}{4} loose",          "c_{3}{4}"         , "c_{3}{4}"         )'
#root -l -b -q 'compare3.C("grV2_sysTight4.root", "grV2_merged.root", "grV2_sysTight2.root", "grV264", "comp_pPb_sysTrack_v264.pdf", "v_{2}{6}/v_{2}{4} tight", "v_{2}{6}/v_{2}{4} loose", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysTight4.root", "grV2_merged.root", "grV2_sysTight2.root", "grV286", "comp_pPb_sysTrack_v286.pdf", "v_{2}{8}/v_{2}{6} tight", "v_{2}{8}/v_{2}{6} loose", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'


#root -l -b -q 'compare3.C("grV2PbPb.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight2.root", "grV24", "comp_PbPb_track_v24.pdf", "v_{2}{4}",       "v_{2}{4} Tighter",       "v_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight2.root", "grC24", "comp_PbPb_track_c24.pdf", "c_{2}{4}",       "c_{2}{4} Tighter",       "c_{2}{4} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight2.root", "grC26", "comp_PbPb_track_c26.pdf", "c_{2}{6}",       "c_{2}{6} Tighter",       "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV2PbPb.root", "grV2PbPb_sysTighter.root", "grV2PbPb_sysTight2.root", "grC28", "comp_PbPb_track_c28.pdf", "c_{2}{8}",       "c_{2}{8} Tighter",       "c_{2}{8} Tight2")'
#root -l -b -q 'compare3.C("grV3PbPb.root", "grV3PbPb_sysTighter.root", "grV3PbPb_sysTight2.root", "grC34", "comp_PbPb_track_c34.pdf", "c_{3}{4}",       "c_{3}{4} Tighter",       "c_{3}{4} Tight2")'




#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC24",  "comp_pPb_sysVz_c24.pdf",           "c_{2}{4} |vz|<3",          "c_{2}{4} 3<|vz|<15",          "c_{2}{4} |vz|<15", "c_{2}{4}"         )'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC26",  "comp_pPb_sysVz_c26.pdf",           "c_{2}{6} |vz|<3",          "c_{2}{6} 3<|vz|<15",          "c_{2}{6} |vz|<15", "c_{2}{6}"         )'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grC28",  "comp_pPb_sysVz_c28.pdf",           "c_{2}{8} |vz|<3",          "c_{2}{8} 3<|vz|<15",          "c_{2}{8} |vz|<15", "c_{2}{8}"         )'
#root -l -b -q 'compare3.C("grV3_sysNarrow2.root", "grV3_sysWide2.root", "grV3_sysTight2.root", "grC34",  "comp_pPb_sysVz_c34.pdf",           "c_{3}{4} |vz|<3",          "c_{3}{4} 3<|vz|<15",          "c_{3}{4} |vz|<15", "c_{3}{4}"         )'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grV264", "comp_pPb_sysVz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3", "v_{2}{6}/v_{2}{4} 3<|vz|<15", "v_{2}{6}/v_{2}{4} |vz|<15", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysNarrow2.root", "grV2_sysWide2.root", "grV2_sysTight2.root", "grV286", "comp_pPb_sysVz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3", "v_{2}{8}/v_{2}{6} 3<|vz|<15", "v_{2}{8}/v_{2}{6} |vz|<15", "v_{2}{8}/v_{2}{6}")'





#root -l -b -q 'compare3.C("grV2_sysHighPU2.root", "grV2_sysLowPU2.root", "grV2_sysTight2.root", "grC24",  "comp_pPb_sysPU_c24.pdf",           "c_{2}{4} HighPU",          "c_{2}{4} LowPU",          "c_{2}{4}",          "c_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHighPU2.root", "grV2_sysLowPU2.root", "grV2_sysTight2.root", "grC26",  "comp_pPb_sysPU_c26.pdf",           "c_{2}{6} HighPU",          "c_{2}{6} LowPU",          "c_{2}{6}",          "c_{2}{6}")'
#root -l -b -q 'compare3.C("grV2_sysHighPU2.root", "grV2_sysLowPU2.root", "grV2_sysTight2.root", "grC28",  "comp_pPb_sysPU_c28.pdf",           "c_{2}{8} HighPU",          "c_{2}{8} LowPU",          "c_{2}{8}",          "c_{2}{8}")'
#root -l -b -q 'compare3.C("grV3_sysHighPU2.root", "grV3_sysLowPU2.root", "grV3_sysTight2.root", "grC34",  "comp_pPb_sysPU_c34.pdf",           "c_{3}{4} HighPU",          "c_{3}{4} LowPU",          "c_{3}{4}",          "c_{3}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHighPU2.root", "grV2_sysLowPU2.root", "grV2_sysTight2.root", "grV264", "comp_pPb_sysPU_v264.pdf", "v_{2}{6}/v_{2}{4} HighPU", "v_{2}{6}/v_{2}{4} LowPU", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHighPU2.root", "grV2_sysLowPU2.root", "grV2_sysTight2.root", "grV286", "comp_pPb_sysPU_v286.pdf", "v_{2}{8}/v_{2}{6} HighPU", "v_{2}{8}/v_{2}{6} LowPU", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'




#root -l -b -q 'compare3.C("grV2_pPb2.root", "grV2_Pbp2.root", "grV2_sysTight2.root", "grC26",  "comp_pPb_sysBeam_c26.pdf",           "c_{2}{6} pPb",          "c_{2}{6} Pbp",          "c_{2}{6}",          "c_{2}{6}")'
#root -l -b -q 'compare3.C("grV2_pPb2.root", "grV2_Pbp2.root", "grV2_sysTight2.root", "grC28",  "comp_pPb_sysBeam_c28.pdf",           "c_{2}{8} pPb",          "c_{2}{8} Pbp",          "c_{2}{8}",          "c_{2}{8}")'
#root -l -b -q 'compare3.C("grV3_pPb2.root", "grV3_Pbp2.root", "grV3_sysTight2.root", "grC34",  "comp_pPb_sysBeam_c34.pdf",           "c_{3}{4} pPb",          "c_{3}{4} Pbp",          "c_{3}{4}",          "c_{3}{4}")'
#root -l -b -q 'compare3.C("grV2_pPb2.root", "grV2_Pbp2.root", "grV2_sysTight2.root", "grV286", "comp_pPb_sysBeam_v286.pdf", "v_{2}{8}/v_{2}{6} pPb", "v_{2}{8}/v_{2}{6} Pbp", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'



#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC24",  "comp_PbPb_sysVz_c24.pdf",           "c_{2}{4} |vz|<3",          "c_{2}{4} 3<|vz|<15",          "c_{2}{4} |vz|<15"),          "c_{2}{4}"'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC26",  "comp_PbPb_sysVz_c26.pdf",           "c_{2}{6} |vz|<3",          "c_{2}{6} 3<|vz|<15",          "c_{2}{6} |vz|<15"),          "c_{2}{6}"'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grC28",  "comp_PbPb_sysVz_c28.pdf",           "c_{2}{8} |vz|<3",          "c_{2}{8} 3<|vz|<15",          "c_{2}{8} |vz|<15"),          "c_{2}{8}"'
#root -l -b -q 'compare3.C("grV3PbPb_sysNarrow2.root", "grV3PbPb_sysWide2.root", "grV3PbPb_sysTight2.root", "grC34",  "comp_PbPb_sysVz_c34.pdf",           "c_{3}{4} |vz|<3",          "c_{3}{4} 3<|vz|<15",          "c_{3}{4} |vz|<15"),          "c_{3}{4}"'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV264", "comp_PbPb_sysVz_v264.pdf", "v_{2}{6}/v_{2}{4} |vz|<3", "v_{2}{6}/v_{2}{4} 3<|vz|<15", "v_{2}{6}/v_{2}{4} |vz|<15"), "v_{2}{6}/v_{2}{4}"'
#root -l -b -q 'compare3.C("grV2PbPb_sysNarrow2.root", "grV2PbPb_sysWide2.root", "grV2PbPb_sysTight2.root", "grV286", "comp_PbPb_sysVz_v286.pdf", "v_{2}{8}/v_{2}{6} |vz|<3", "v_{2}{8}/v_{2}{6} 3<|vz|<15", "v_{2}{8}/v_{2}{6} |vz|<15"), "v_{2}{8}/v_{2}{6}"'


#root -l -b -q 'compare3.C("grV2_sysHLT2.root", "grV2_sysHLT2.root", "grV2_sysTight2.root", "grC24",  "comp_pPb_sysHLT2_c24.pdf",           "c_{2}{4} HLT",          "c_{2}{4} HLT",          "c_{2}{4}",          "c_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHLT2.root", "grV2_sysHLT2.root", "grV2_sysTight2.root", "grC26",  "comp_pPb_sysHLT2_c26.pdf",           "c_{2}{6} HLT",          "c_{2}{6} HLT",          "c_{2}{6}",          "c_{2}{6}")'
#root -l -b -q 'compare3.C("grV2_sysHLT2.root", "grV2_sysHLT2.root", "grV2_sysTight2.root", "grC28",  "comp_pPb_sysHLT2_c28.pdf",           "c_{2}{8} HLT",          "c_{2}{8} HLT",          "c_{2}{8}",          "c_{2}{8}")'
#root -l -b -q 'compare3.C("grV3_sysHLT2.root", "grV3_sysHLT2.root", "grV3_sysTight2.root", "grC34",  "comp_pPb_sysHLT2_c34.pdf",           "c_{3}{4} HLT",          "c_{3}{4} HLT",          "c_{3}{4}",          "c_{3}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHLT2.root", "grV2_sysHLT2.root", "grV2_sysTight2.root", "grV264", "comp_pPb_sysHLT2_v264.pdf", "v_{2}{6}/v_{2}{4} HLT", "v_{2}{6}/v_{2}{4} HLT", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2_sysHLT2.root", "grV2_sysHLT2.root", "grV2_sysTight2.root", "grV286", "comp_pPb_sysHLT2_v286.pdf", "v_{2}{8}/v_{2}{6} HLT", "v_{2}{8}/v_{2}{6} HLT", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'


#root -l -b -q 'compare3.C("grV2PbPb_sysTight4.root", "grV2PbPb.root", "grV2PbPb_sysTight2.root", "grC24",  "comp_PbPb_sysTrack_c24.pdf",           "c_{2}{4} tight",          "c_{2}{4} loose",          "c_{2}{4}",          "c_{2}{4}")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight4.root", "grV2PbPb.root", "grV2PbPb_sysTight2.root", "grC26",  "comp_PbPb_sysTrack_c26.pdf",           "c_{2}{6} tight",          "c_{2}{6} loose",          "c_{2}{6}",          "c_{2}{6}")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight4.root", "grV2PbPb.root", "grV2PbPb_sysTight2.root", "grC28",  "comp_PbPb_sysTrack_c28.pdf",           "c_{2}{8} tight",          "c_{2}{8} loose",          "c_{2}{8}",          "c_{2}{8}")'
#root -l -b -q 'compare3.C("grV3PbPb_sysTight4.root", "grV3PbPb.root", "grV3PbPb_sysTight2.root", "grC34",  "comp_PbPb_sysTrack_c34.pdf",           "c_{3}{4} tight",          "c_{3}{4} loose",          "c_{3}{4}",          "c_{3}{4}")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight4.root", "grV2PbPb.root", "grV2PbPb_sysTight2.root", "grV264", "comp_PbPb_sysTrack_v264.pdf", "v_{2}{6}/v_{2}{4} tight", "v_{2}{6}/v_{2}{4} loose", "v_{2}{6}/v_{2}{4}", "v_{2}{6}/v_{2}{4}")'
#root -l -b -q 'compare3.C("grV2PbPb_sysTight4.root", "grV2PbPb.root", "grV2PbPb_sysTight2.root", "grV286", "comp_PbPb_sysTrack_v286.pdf", "v_{2}{8}/v_{2}{6} tight", "v_{2}{8}/v_{2}{6} loose", "v_{2}{8}/v_{2}{6}", "v_{2}{8}/v_{2}{6}")'













#root -l -b -q 'compare3.C("grV2PbPb_sysLooseXCentCut.root", "grV2PbPb_sysLooseSkim.root", "grV2PbPb_sysLoose.root", "grC24", "comp_PbPb_sysLoose_c24.pdf", "v_{2}{4} LooseXCentCut",       "v_{2}{4} LooseSkim",       "v_{2}{4} Loose", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoose.root", "grV2PbPb_sysLooseSkim.root", "grV2PbPb.root", "grC24", "comp_PbPb_sysLooseSkim_c24.pdf", "v_{2}{4} Loose",       "v_{2}{4} LooseSkim",       "v_{2}{4} standard", "c_{2}{4}" )'

#root -l -b -q 'compare3.C("grV2PbPb_sysLoose.root", "grV2PbPb_sysLoosePt01.root", "grV2PbPb.root", "grC24", "comp_c24.pdf", "c_{2}{4} Loose",       "c_{2}{4} LoosePt01",       "c_{2}{4} standard", "c_{2}{4}" )'

#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grV22", "comp_v22.pdf", "v_{2}{2} Loose",       "v_{2}{2} Tight",       "v_{2}{2} standard", "v_{2}{2}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC22", "comp_c22.pdf", "c_{2}{2} Loose",       "c_{2}{2} Tight",       "c_{2}{2} standard", "c_{2}{2}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC24", "comp_c24.pdf", "c_{2}{4} Loose",       "c_{2}{4} Tight",       "c_{2}{4} standard", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC26", "comp_c26.pdf", "c_{2}{6} Loose",       "c_{2}{6} Tight",       "c_{2}{6} standard", "c_{2}{6}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC28", "comp_c28.pdf", "c_{2}{8} Loose",       "c_{2}{8} Tight",       "c_{2}{8} standard", "c_{2}{8}" )'

#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysTight_HFcut.root", "grV2PbPb_HFcut.root", "grC24", "comp_c24.pdf", "c_{2}{4} Loose",       "c_{2}{4} Tight",       "c_{2}{4} standard", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysTight_HFcut.root", "grV2PbPb_HFcut.root", "grC26", "comp_c26.pdf", "c_{2}{6} Loose",       "c_{2}{6} Tight",       "c_{2}{6} standard", "c_{2}{6}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysTight_HFcut.root", "grV2PbPb_HFcut.root", "grC28", "comp_c28.pdf", "c_{2}{8} Loose",       "c_{2}{8} Tight",       "c_{2}{8} standard", "c_{2}{8}" )'
#root -l -b -q 'compare3.C("grV3PbPb_sysLoosePt01_HFcut.root", "grV3PbPb_sysTight_HFcut.root", "grV3PbPb_HFcut.root", "grC34", "comp_c34.pdf", "c_{3}{4} Loose",       "c_{3}{4} Tight",       "c_{3}{4} standard", "c_{2}{4}" )'

#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC24", "comp_c24.pdf", "c_{2}{4} Loose HFcuts NoScrap",       "c_{2}{4} Tight",       "c_{2}{4} standard", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC26", "comp_c26.pdf", "c_{2}{6} Loose HFcuts NoScrap",       "c_{2}{6} Tight",       "c_{2}{6} standard", "c_{2}{6}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grV2PbPb_sysTight.root", "grV2PbPb.root", "grC28", "comp_c28.pdf", "c_{2}{8} Loose HFcuts NoScrap",       "c_{2}{8} Tight",       "c_{2}{8} standard", "c_{2}{8}" )'



#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysLoosePt01_NoScrap.root", "grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grC24", "comp_c24_loose.pdf", "c_{2}{4} Loose HFcuts",       "c_{2}{4} Loose NoScrap",       "c_{2}{4} Loose HFcuts NoScrap", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysLoosePt01_NoScrap.root", "grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grC26", "comp_c26_loose.pdf", "c_{2}{6} Loose HFcuts",       "c_{2}{6} Loose NoScrap",       "c_{2}{6} Loose HFcuts NoScrap", "c_{2}{6}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_HFcut.root", "grV2PbPb_sysLoosePt01_NoScrap.root", "grV2PbPb_sysLoosePt01_HFcut_NoScrap.root", "grC28", "comp_c28_loose.pdf", "c_{2}{8} Loose HFcuts",       "c_{2}{8} Loose NoScrap",       "c_{2}{8} Loose HFcuts NoScrap", "c_{2}{8}" )'



#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_sysTight_GMO.root", "grV2PbPb_GMO.root", "grC22", "comp_PbPbTrk_c22.pdf", "c_{2}{2} Loose",       "c_{2}{2} Tight",       "c_{2}{2} standard", "c_{2}{2}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_sysTight_GMO.root", "grV2PbPb_GMO.root", "grC24", "comp_PbPbTrk_c24.pdf", "c_{2}{4} Loose",       "c_{2}{4} Tight",       "c_{2}{4} standard", "c_{2}{4}" )'
#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_sysTight_GMO.root", "grV2PbPb_GMO.root", "grC26", "comp_PbPbTrk_c26.pdf", "c_{2}{6} Loose",       "c_{2}{6} Tight",       "c_{2}{6} standard", "c_{2}{6}" )'

#root -l -b -q 'compare3.C("grV2PbPb_sysLoosePt01_GMO.root", "grV2PbPb_sysTight_GMO.root", "grV2PbPb_GMO.root", "grC28", "comp_PbPbTrk_c28.pdf", "c_{2}{8} Loose",       "c_{2}{8} Tight",       "c_{2}{8} standard", "c_{2}{8}" )'
#root -l -b -q 'compare3.C("grV3PbPb_sysLoosePt01_GMO.root", "grV3PbPb_sysTight_GMO.root", "grV3PbPb_GMO.root", "grC34", "comp_PbPbTrk_c34.pdf", "c_{3}{4} Loose",       "c_{3}{4} Tight",       "c_{3}{4} standard", "c_{3}{4}" )'



