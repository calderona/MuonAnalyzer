
void doCompare() { 


// LOADING MACROS. 
  gROOT->LoadMacro("../utils/TResultsTable.C+");
  gInterpreter->LoadMacro   ("../utils/draw.C+");
  gInterpreter->LoadMacro   ("../utils/utils.C+"); 
  gInterpreter->ExecuteMacro("../utils/ChargeRatioStyle.C");
  gStyle      ->SetOptStat  (0);
  gStyle      ->SetPalette  (1);



//------------------------------------------------------------------------------
// Define plots to print
//------------------------------------------------------------------------------

  bool doHWW = 0; 
  bool doHWWEff = 0; 
  bool doHWWPFIso = 0;
  bool doHWWTuneMuIDEff = 0; 

  bool doWjets = 1;
  bool doWjetsEff = 0; 
  bool doWjetsPFIso = 0;
  bool doWjetsTuneMuIDEff = 0; 

  bool doROCcurves_TKLayers = 0;
  bool doROCcurves_TightMu_TKLayers = 0;
  bool doROCcurves_PixelHits = 0;
  bool doROCcurves_STAHits = 0;

  bool doROCcurves_Dilepton_TKLayers = 0;
  bool doROCcurves_Dilepton_STAHits = 0;
  
  bool  doSignalOverBackg = 0; 


//------------------------------------------------------------------------------
// Files and variables
//------------------------------------------------------------------------------


 TFile* f_HWW_8TeV = 0;
 TFile* f_HWW_PUS14 = 0;
 TFile* f_HWW_PU20bx25 = 0;

 f_HWW_8TeV  = TFile::Open("../files/csa14_MC_GGHWW_8TeV_PFCHIsolation_NewPVSel.root");
 f_HWW_PUS14 = TFile::Open("../files/csa14_MC_GGHWW_S14_PFCHIsolation_NewPVSel.root");
 f_HWW_PU20bx25 = TFile::Open("../files/csa14_MC_GGHWW_PU20bx25_PFCHIsolation_NewPVSel.root");


 TFile* f_Wjets_8TeV = 0;
 TFile* f_Wjets_PUS14 = 0;
 TFile* f_Wjets_PU20bx25 = 0;

 f_Wjets_8TeV  = TFile::Open("../files/csa14_MC_Wjets_8TeV_PFCHIsolation_NewPVSel.root");
 f_Wjets_PUS14 = TFile::Open("../files/csa14_MC_Wjets_S14_PFCHIsolation_NewPVSel.root");
 f_Wjets_PU20bx25 = TFile::Open("../files/csa14_MC_Wjets_PU20bx25_PFCHIsolation_NewPVSel.root");




//------------------------------------------------------------------------------
// Plots from 8TeV samples 
//------------------------------------------------------------------------------

// ----> GluGlu To H To WW 

 f_HWW_8TeV->cd();

 TH1F *h_hww_8TeV_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dz_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dz_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_hww_8TeV_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_8TeV_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_hww_8TeV_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_8TeV_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_hww_8TeV_Dilep_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_8TeV_WWlevel_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();

 TH1F *h_hww_8TeV_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_hww_8TeV_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_hww_8TeV_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();


// ----> Wjets

 f_Wjets_8TeV->cd();

 TH1F *h_wjets_8TeV_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();

 TH2F *h_wjets_8TeV_Dilep_stahitsEta_Mu1 = (TH2F*) h_Dilep_StaHitsEta_Mu1->Clone();
TH2F *h_wjets_8TeV_Dilep_stahitsPV_Mu1 = (TH2F*) h_Dilep_StaHitsPV_Mu1->Clone();
 TH2F *h_wjets_8TeV_Dilep_stahitsEta_Mu2 = (TH2F*) h_Dilep_StaHitsEta_Mu2->Clone();
TH2F *h_wjets_8TeV_Dilep_stahitsPV_Mu2 = (TH2F*) h_Dilep_StaHitsPV_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dzMu_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dzMu_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_TM_tkL_Mu1 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_TM_tkL_Mu2 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_8TeV_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_wjets_8TeV_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_8TeV_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_wjets_8TeV_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();

 TH1F *h_wjets_8TeV_Dilep_PFCH_Mu1 =  (TH1F*)  h_Dilep_TightMu_PFCH_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFCH_Mu2 =  (TH1F*)  h_Dilep_TightMu_PFCH_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFNH_Mu1 =  (TH1F*)  h_Dilep_TightMu_PFNH_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFNH_Mu2 =  (TH1F*)  h_Dilep_TightMu_PFNH_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFPh_Mu1 =  (TH1F*)  h_Dilep_TightMu_PFPh_Mu1->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFPh_Mu2 =  (TH1F*)  h_Dilep_TightMu_PFPh_Mu2->Clone();
 TH1F *h_wjets_8TeV_Dilep_PFRho_Mu1 =  (TH1F*)  h_Dilep_TightMu_PFRho_Mu1->Clone();
  TH1F *h_wjets_8TeV_Dilep_PFRho_Mu2 =  (TH1F*)  h_Dilep_TightMu_PFRho_Mu2->Clone();



//------------------------------------------------------------------------------
// Plots from PUS14 13TeV  samples 
//------------------------------------------------------------------------------

// ----> GluGlu To H To WW 

 f_HWW_PUS14->cd();

 TH1F *h_hww_PUS14_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dz_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dz_Mu2->Clone();

 TH1F *h_hww_PUS14_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_hww_PUS14_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();

 TH1F *h_hww_PUS14_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();
 
 TH1F *h_hww_PUS14_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PUS14_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_hww_PUS14_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PUS14_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_hww_PUS14_Dilep_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PUS14_WWlevel_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();

 TH1F *h_hww_PUS14_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_hww_PUS14_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_hww_PUS14_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_hww_PUS14_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_hww_PUS14_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();

// ----> Wjets

 f_Wjets_PUS14->cd();

 TH1F *h_wjets_PUS14_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();

TH2F *h_wjets_PUS14_Dilep_stahitsEta_Mu1 = (TH2F*) h_Dilep_StaHitsEta_Mu1->Clone();
 TH2F *h_wjets_PUS14_Dilep_stahitsPV_Mu1 = (TH2F*) h_Dilep_StaHitsPV_Mu1->Clone();
 TH2F *h_wjets_PUS14_Dilep_stahitsEta_Mu2 = (TH2F*) h_Dilep_StaHitsEta_Mu2->Clone();
 TH2F *h_wjets_PUS14_Dilep_stahitsPV_Mu2 = (TH2F*) h_Dilep_StaHitsPV_Mu2->Clone();


 TH1F *h_wjets_PUS14_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dzMu_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dzMu_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_TM_tkL_Mu1 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_TM_tkL_Mu2 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_wjets_PUS14_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_PUS14_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_wjets_PUS14_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_PUS14_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_wjets_PUS14_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_PUS14_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_PUS14_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();

//------------------------------------------------------------------------------
// Plots from PU20bx25 13TeV  samples 
//------------------------------------------------------------------------------

// ----> GluGlu To H To WW 

 f_HWW_PU20bx25->cd();

 TH1F *h_hww_PU20bx25_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dz_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dz_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_hww_PU20bx25_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PU20bx25_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_hww_PU20bx25_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PU20bx25_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_hww_PU20bx25_Dilep_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();

 TH1F *h_hww_PU20bx25_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_hww_PU20bx25_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_hww_PU20bx25_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();

// ----> Wjets

 f_Wjets_PU20bx25->cd();

 TH1F *h_wjets_PU20bx25_Dilep_chi2_Mu1 = (TH1F*) h_Dilep_Chi2_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_chi2_Mu2 = (TH1F*) h_Dilep_Chi2_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_stahits_Mu1 = (TH1F*) h_Dilep_StaHits_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_stahits_Mu2 = (TH1F*) h_Dilep_StaHits_Mu2->Clone();

 TH2F *h_wjets_PU20bx25_Dilep_stahitsEta_Mu1 = (TH2F*) h_Dilep_StaHitsEta_Mu1->Clone();
 TH2F *h_wjets_PU20bx25_Dilep_stahitsPV_Mu1 = (TH2F*) h_Dilep_StaHitsPV_Mu1->Clone();
 TH2F *h_wjets_PU20bx25_Dilep_stahitsEta_Mu2 = (TH2F*) h_Dilep_StaHitsEta_Mu2->Clone();
 TH2F *h_wjets_PU20bx25_Dilep_stahitsPV_Mu2 = (TH2F*) h_Dilep_StaHitsPV_Mu2->Clone();


 TH1F *h_wjets_PU20bx25_Dilep_nsta_Mu1 = (TH1F*) h_Dilep_StaNStation_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_nsta_Mu2 = (TH1F*) h_Dilep_StaNStation_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_pixelH_Mu1 = (TH1F*) h_Dilep_PixelHits_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_pixelH_Mu2 = (TH1F*) h_Dilep_PixelHits_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_tkL_Mu1 = (TH1F*) h_Dilep_TkLayers_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_tkL_Mu2 = (TH1F*) h_Dilep_TkLayers_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_dxy_Mu1 = (TH1F*) h_Dilep_dxy_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_dxy_Mu2 = (TH1F*) h_Dilep_dxy_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_dz_Mu1 = (TH1F*) h_Dilep_dzMu_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_dz_Mu2 = (TH1F*) h_Dilep_dzMu_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_TM_tkL_Mu1 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_TM_tkL_Mu2 = (TH1F*) h_Dilep_TightMuon_TkLayers_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_Eff_Mu1 = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_Eff_Mu2 = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_Eff_Mu1_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_Eff_Mu2_norm = (TH1F*) h_Dilep_TightMu_RelEff_Mu2->Clone();
 
 TH1F *h_wjets_PU20bx25_Dilep_PFIso_Mu1 = (TH1F*) h_Dilep_TightMu_PFIsoBeta_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_PFIso_Mu2 = (TH1F*) h_Dilep_TihgtMu_PFIsoBeta_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_TigtMuCuts =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_PU20bx25_WWlevel_TigtMuCuts =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_TigtMuCuts_norm =  (TH1F*) h_N_Dilep_TigtMuCuts->Clone();
 TH1F *h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm =  (TH1F*) h_N_WWlevel_TigtMuCuts->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_2Lep_staH_Mu1  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_2Lep_staH_Mu2  =  (TH1F*) h_N_Dilep_TightMuCuts_butSTAHits_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butTkLayers_Mu2->Clone();

 TH1F *h_wjets_PU20bx25_Dilep_GLBPF_staH_Mu1  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu1->Clone();
 TH1F *h_wjets_PU20bx25_Dilep_GLBPF_staH_Mu2  =  (TH1F*) h_N_Dilep_GLBPF_butSTAHits_Mu2->Clone();

//------------------------------------------------------------------------------
// Make Plots
//------------------------------------------------------------------------------


if (doROCcurves_Dilepton_TKLayers) {

   TGraph *h_ROC_PU20bx25_Dilep_tklayers; 
   TGraph *h_ROC_PUS14_Dilep_tklayers; 
   TGraph *h_ROC_8tev_Dilep_tklayers; 


   int NcutTkLayers = 8;

   //h_wjets_PU20bx25_Dilep_2Lep_GLBPF_Mu1
     //float hwwintTkLayers2025 = h_hww_PU20bx25_Dilep_2Lep_tkL_Mu1->Integral()*2;
     //float wjetsintTkLayers2025

   
   float hwwintTkLayers8tev =  h_hww_8TeV_Dilep_GLBPF_tkL_Mu1->Integral() +
     h_hww_8TeV_Dilep_GLBPF_tkL_Mu2->Integral();

   float wjetsintTkLayers8tev = h_wjets_8TeV_Dilep_GLBPF_tkL_Mu1->Integral() +
     h_wjets_8TeV_Dilep_GLBPF_tkL_Mu2->Integral();
   
   float hwwintTkLayersS14 = h_hww_PUS14_Dilep_GLBPF_tkL_Mu1->Integral() +
     h_hww_PUS14_Dilep_GLBPF_tkL_Mu2->Integral() ;
   float wjetsintTkLayersS14 = h_wjets_PUS14_Dilep_GLBPF_tkL_Mu1->Integral() +
     h_wjets_PUS14_Dilep_GLBPF_tkL_Mu2->Integral();

   float hwwintTkLayers2025 = h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu1->Integral() + 
     h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu2->Integral();
   float wjetsintTkLayers2025 = h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu1->Integral() + 
     h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu2->Integral(); 
   

   /*   
   float hwwintTkLayers8tev =h_hww_8TeV_Dilep_2Lep_tkL_Mu1->Integral() +
     h_hww_8TeV_Dilep_2Lep_tkL_Mu2->Integral();
   float wjetsintTkLayers8tev = h_wjets_8TeV_Dilep_2Lep_tkL_Mu1->Integral() +
     h_wjets_8TeV_Dilep_2Lep_tkL_Mu2->Integral();
     
   float hwwintTkLayersS14 = h_hww_PUS14_Dilep_2Lep_tkL_Mu1->Integral() + 
     h_hww_PUS14_Dilep_2Lep_tkL_Mu2->Integral();
   float wjetsintTkLayersS14 = h_wjets_PUS14_Dilep_2Lep_tkL_Mu1->Integral() +
     h_wjets_PUS14_Dilep_2Lep_tkL_Mu2->Integral();

   float hwwintTkLayers2025 = h_hww_PU20bx25_Dilep_2Lep_tkL_Mu1->Integral() +
     h_hww_PU20bx25_Dilep_2Lep_tkL_Mu2->Integral();
   float wjetsintTkLayers2025 = h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu1->Integral() + 
     h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu2->Integral();
   */


   float eff2025hww[11], eff2025wjets [11],  effS14hww [11], effS14wjets [11], eff8tevhww [11], eff8tevwjets [11];


   for ( int c = 0; c < NcutTkLayers; c++ ) {

          eff8tevhww [c] =  (h_hww_8TeV_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_hww_8TeV_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayers8tev;
     eff8tevwjets [c] = (h_wjets_8TeV_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_wjets_8TeV_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/wjetsintTkLayers8tev;

     effS14hww [c] =  (h_hww_PUS14_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_hww_PUS14_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayersS14;
     effS14wjets [c] = (h_wjets_PUS14_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_wjets_PUS14_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/wjetsintTkLayersS14;
    
     eff2025hww [c] =  (h_hww_PU20bx25_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_hww_PU20bx25_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayers2025;
     eff2025wjets [c] = (h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu1->Integral(c+4, 20) + h_wjets_PU20bx25_Dilep_2Lep_tkL_Mu2->Integral(c+4, 20))/wjetsintTkLayers2025;
     

     /*
     eff8tevhww [c] = (h_hww_8TeV_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20) + h_hww_8TeV_Dilep_GLBPF_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayers8tev;
     eff8tevwjets [c] = (h_wjets_8TeV_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20) +  h_wjets_8TeV_Dilep_GLBPF_tkL_Mu2->Integral(c+4, 20))/wjetsintTkLayers8tev;
     effS14hww [c] = ( h_hww_PUS14_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20) + h_hww_PUS14_Dilep_GLBPF_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayersS14;  
     effS14wjets [c] = (h_wjets_PUS14_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20) + h_wjets_PUS14_Dilep_GLBPF_tkL_Mu2->Integral(c+4, 20))/wjetsintTkLayersS14;
     eff2025hww [c] =  (h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20) + h_hww_PU20bx25_Dilep_GLBPF_tkL_Mu2->Integral(c+4, 20))/hwwintTkLayers2025;
     eff2025wjets [c] = (h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu1->Integral(c+4, 20)+h_wjets_PU20bx25_Dilep_GLBPF_tkL_Mu2->Integral(c+4,20))/wjetsintTkLayers2025;
*/
 cout << eff8tevhww [c] <<  "  " << eff8tevwjets [c] << "\t";
   cout << effS14hww [c] <<  "  " << effS14wjets [c] <<  "\t";
 
    cout << eff2025hww [c] <<  "  " << eff2025wjets [c] << endl;

   }


   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_tklayers = new TGraph(NcutTkLayers, eff2025wjets, eff2025hww);
   h_ROC_PU20bx25_Dilep_tklayers->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_tklayers->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_tklayers->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_tklayers->SetMarkerStyle(kFullCircle);
   

   h_ROC_PUS14_Dilep_tklayers = new TGraph(NcutTkLayers, effS14wjets, effS14hww);
   h_ROC_PUS14_Dilep_tklayers->SetLineColor(6);
   h_ROC_PUS14_Dilep_tklayers->SetLineWidth(2);
   h_ROC_PUS14_Dilep_tklayers->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_tklayers->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_tklayers = new TGraph(NcutTkLayers, eff8tevwjets, eff8tevhww);
   h_ROC_8tev_Dilep_tklayers->SetLineColor(4);
   h_ROC_8tev_Dilep_tklayers->SetLineWidth(2);
   h_ROC_8tev_Dilep_tklayers->SetMarkerColor(4);
   h_ROC_8tev_Dilep_tklayers->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_tklayers,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_tklayers,"");
   wjets_ROC->Add(h_ROC_PU20bx25_Dilep_tklayers,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("HWW vs WJets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("WJets cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("HWW cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_tklayers , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_tklayers , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_tklayers , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }


if (doROCcurves_Dilepton_STAHits) {

   TGraph *h_ROC_PU20bx25_Dilep_stahits; 
   TGraph *h_ROC_PUS14_Dilep_stahits; 
   TGraph *h_ROC_8tev_Dilep_stahits; 


   int NcutSTAHits = 11;

      
   float hwwintSTAHits8tev = h_hww_8TeV_Dilep_2Lep_staH_Mu1->Integral()*2;
   float wjetsintSTAHits8tev = h_wjets_8TeV_Dilep_2Lep_staH_Mu1->Integral()*2;
     
   float hwwintSTAHitsS14 = h_hww_PUS14_Dilep_2Lep_staH_Mu1->Integral()*2;
   float wjetsintSTAHitsS14 = h_wjets_PUS14_Dilep_2Lep_staH_Mu1->Integral()*2;

   float hwwintSTAHits2025 = h_hww_PU20bx25_Dilep_2Lep_staH_Mu1->Integral()*2;
   float wjetsintSTAHits2025 = h_wjets_PU20bx25_Dilep_2Lep_staH_Mu1->Integral()*2;


   float eff2025hww[11], eff2025wjets [11],  effS14hww [11], effS14wjets [11], eff8tevhww [11], eff8tevwjets [11];


   for ( int c = 0; c < NcutSTAHits; c++ ) {

     eff8tevhww [c] =  (h_hww_8TeV_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_hww_8TeV_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/hwwintSTAHits8tev;
     eff8tevwjets [c] = (h_wjets_8TeV_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_wjets_8TeV_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/wjetsintSTAHits8tev;

     effS14hww [c] =  (h_hww_PUS14_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_hww_PUS14_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/hwwintSTAHitsS14;
     effS14wjets [c] = (h_wjets_PUS14_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_wjets_PUS14_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/wjetsintSTAHitsS14;
    
     eff2025hww [c] =  (h_hww_PU20bx25_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_hww_PU20bx25_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/hwwintSTAHits2025;
     eff2025wjets [c] = (h_wjets_PU20bx25_Dilep_2Lep_staH_Mu1->Integral(c+2, 50) + h_wjets_PU20bx25_Dilep_2Lep_staH_Mu2->Integral(c+2, 50))/wjetsintSTAHits2025;
     

     cout << eff8tevhww [c] <<  "  " << eff8tevwjets [c] << endl;
   }


   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_stahits = new TGraph(NcutSTAHits, eff2025wjets, eff2025hww);
   h_ROC_PU20bx25_Dilep_stahits->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_stahits->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_stahits->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_stahits->SetMarkerStyle(kFullCircle);
   

   h_ROC_PUS14_Dilep_stahits = new TGraph(NcutSTAHits, effS14wjets, effS14hww);
   h_ROC_PUS14_Dilep_stahits->SetLineColor(6);
   h_ROC_PUS14_Dilep_stahits->SetLineWidth(2);
   h_ROC_PUS14_Dilep_stahits->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_stahits->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_stahits = new TGraph(NcutSTAHits, eff8tevwjets, eff8tevhww);
   h_ROC_8tev_Dilep_stahits->SetLineColor(4);
   h_ROC_8tev_Dilep_stahits->SetLineWidth(2);
   h_ROC_8tev_Dilep_stahits->SetMarkerColor(4);
   h_ROC_8tev_Dilep_stahits->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_stahits,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_stahits,"");
    wjets_ROC->Add(h_ROC_PU20bx25_Dilep_stahits,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("HWW vs WJets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("WJets cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("HWW cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_stahits , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_stahits , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_stahits , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }


 if (doROCcurves_TKLayers) {

   TGraph *h_ROC_PU20bx25_Dilep_tklayers; 
   TGraph *h_ROC_PUS14_Dilep_tklayers; 
   TGraph *h_ROC_8tev_Dilep_tklayers; 


   int NcutTkLayers = 8;
   float intTkLayers2025Mu1 = h_wjets_PU20bx25_Dilep_tkL_Mu1->Integral();
   float intTkLayers2025Mu2 = h_wjets_PU20bx25_Dilep_tkL_Mu2->Integral();

   float intTkLayersS14Mu1 = h_wjets_PUS14_Dilep_tkL_Mu1->Integral();
   float intTkLayersS14Mu2 = h_wjets_PUS14_Dilep_tkL_Mu2->Integral();
      
   float intTkLayers8tevMu1 = h_wjets_8TeV_Dilep_tkL_Mu1->Integral();
   float intTkLayers8tevMu2 = h_wjets_8TeV_Dilep_tkL_Mu2->Integral();
      

   float eff2025Mu1 [10], eff2025Mu2 [10],  effS14Mu1 [10], effS14Mu2 [10], eff8tevMu1 [10], eff8tevMu2 [10];


   for ( int c = 0; c < NcutTkLayers; c++ ) {

     eff2025Mu1 [c] =  (h_wjets_PU20bx25_Dilep_tkL_Mu1->Integral(c+4, 20))/intTkLayers2025Mu1;
     eff2025Mu2 [c] =  (h_wjets_PU20bx25_Dilep_tkL_Mu2->Integral(c+4, 20))/intTkLayers2025Mu2;

     effS14Mu1 [c] =  (h_wjets_PUS14_Dilep_tkL_Mu1->Integral(c+4, 20))/intTkLayersS14Mu1;
     effS14Mu2 [c] =  (h_wjets_PUS14_Dilep_tkL_Mu2->Integral(c+4, 20))/intTkLayersS14Mu2;

     eff8tevMu1 [c] =  (h_wjets_8TeV_Dilep_tkL_Mu1->Integral(c+4, 20))/intTkLayers8tevMu1;
     eff8tevMu2 [c] =  (h_wjets_8TeV_Dilep_tkL_Mu2->Integral(c+4, 20))/intTkLayers8tevMu2;

     cout << eff2025Mu1 [c] <<  "  " << eff2025Mu2 [c] << endl;
   }

   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_tklayers = new TGraph(NcutTkLayers, eff2025Mu2, eff2025Mu1);
   h_ROC_PU20bx25_Dilep_tklayers->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_tklayers->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_tklayers->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_tklayers->SetMarkerStyle(kFullCircle);
  
   h_ROC_PUS14_Dilep_tklayers = new TGraph(NcutTkLayers, effS14Mu2, effS14Mu1);
   h_ROC_PUS14_Dilep_tklayers->SetLineColor(6);
   h_ROC_PUS14_Dilep_tklayers->SetLineWidth(2);
   h_ROC_PUS14_Dilep_tklayers->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_tklayers->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_tklayers = new TGraph(NcutTkLayers, eff8tevMu2, eff8tevMu1);
   h_ROC_8tev_Dilep_tklayers->SetLineColor(4);
   h_ROC_8tev_Dilep_tklayers->SetLineWidth(2);
   h_ROC_8tev_Dilep_tklayers->SetMarkerColor(4);
   h_ROC_8tev_Dilep_tklayers->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_tklayers,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_tklayers,"");
   wjets_ROC->Add(h_ROC_PU20bx25_Dilep_tklayers,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("Wjets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("'Fake' muon cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("Prompt muon cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_tklayers , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_tklayers , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_tklayers , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }

 if (doROCcurves_TightMu_TKLayers) {

   TGraph *h_ROC_PU20bx25_Dilep_tightMu_tklayers; 
   TGraph *h_ROC_PUS14_Dilep_tightMu_tklayers; 
   TGraph *h_ROC_8tev_Dilep_tightMu_tklayers; 


   int NcutTkLayers = 8;
   float intTkLayers2025Mu1 = h_wjets_PU20bx25_Dilep_tkL_Mu1->Integral();
   float intTkLayers2025Mu2 = h_wjets_PU20bx25_Dilep_tkL_Mu2->Integral();

   float intTkLayersS14Mu1 = h_wjets_PUS14_Dilep_tkL_Mu1->Integral();
   float intTkLayersS14Mu2 = h_wjets_PUS14_Dilep_tkL_Mu2->Integral();
      
   float intTkLayers8tevMu1 = h_wjets_8TeV_Dilep_tkL_Mu1->Integral();
   float intTkLayers8tevMu2 = h_wjets_8TeV_Dilep_tkL_Mu2->Integral();
      

   float eff2025Mu1 [8], eff2025Mu2 [8],  effS14Mu1 [8], effS14Mu2 [8], eff8tevMu1 [8], eff8tevMu2 [8];


   for ( int c = 0; c < NcutTkLayers; c++ ) {

     eff2025Mu1 [c] =  (h_wjets_PU20bx25_Dilep_TM_tkL_Mu1->Integral(c+4, 20))/intTkLayers2025Mu1;
     eff2025Mu2 [c] =  (h_wjets_PU20bx25_Dilep_TM_tkL_Mu2->Integral(c+4, 20))/intTkLayers2025Mu2;

     effS14Mu1 [c] =  (h_wjets_PUS14_Dilep_TM_tkL_Mu1->Integral(c+4, 20))/intTkLayersS14Mu1;
     effS14Mu2 [c] =  (h_wjets_PUS14_Dilep_TM_tkL_Mu2->Integral(c+4, 20))/intTkLayersS14Mu2;

     eff8tevMu1 [c] =  (h_wjets_8TeV_Dilep_TM_tkL_Mu1->Integral(c+4, 20))/intTkLayers8tevMu1;
     eff8tevMu2 [c] =  (h_wjets_8TeV_Dilep_TM_tkL_Mu2->Integral(c+4, 20))/intTkLayers8tevMu2;

     cout << eff8tevMu1 [c] <<  "  " << eff8tevMu2 [c] << "\t";
   cout << effS14Mu1 [c] <<  "  " << effS14Mu2 [c] <<  "\t";
 
    cout << eff2025Mu1 [c] <<  "  " << eff2025Mu2 [c] << endl;
   }

   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_tightMu_tklayers = new TGraph(NcutTkLayers, eff2025Mu2, eff2025Mu1);
   h_ROC_PU20bx25_Dilep_tightMu_tklayers->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_tightMu_tklayers->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_tightMu_tklayers->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_tightMu_tklayers->SetMarkerStyle(kFullCircle);
  
   h_ROC_PUS14_Dilep_tightMu_tklayers = new TGraph(NcutTkLayers, effS14Mu2, effS14Mu1);
   h_ROC_PUS14_Dilep_tightMu_tklayers->SetLineColor(6);
   h_ROC_PUS14_Dilep_tightMu_tklayers->SetLineWidth(2);
   h_ROC_PUS14_Dilep_tightMu_tklayers->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_tightMu_tklayers->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_tightMu_tklayers = new TGraph(NcutTkLayers, eff8tevMu2, eff8tevMu1);
   h_ROC_8tev_Dilep_tightMu_tklayers->SetLineColor(4);
   h_ROC_8tev_Dilep_tightMu_tklayers->SetLineWidth(2);
   h_ROC_8tev_Dilep_tightMu_tklayers->SetMarkerColor(4);
   h_ROC_8tev_Dilep_tightMu_tklayers->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_tightMu_tklayers,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_tightMu_tklayers,"");
   wjets_ROC->Add(h_ROC_PU20bx25_Dilep_tightMu_tklayers,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("Wjets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("'Fake' muon cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("Prompt muon cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_tightMu_tklayers , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_tightMu_tklayers , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_tightMu_tklayers , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }

if (doROCcurves_PixelHits) {


   TGraph *h_ROC_PU20bx25_Dilep_pixhits; 
   TGraph *h_ROC_PUS14_Dilep_pixhits; 
   TGraph *h_ROC_8tev_Dilep_pixhits; 


   int NcutPixhits = 5;
   float intPixhits2025Mu1 = h_wjets_PU20bx25_Dilep_pixelH_Mu1->Integral();
   float intPixhits2025Mu2 = h_wjets_PU20bx25_Dilep_pixelH_Mu2->Integral();

   float intPixhitsS14Mu1 = h_wjets_PUS14_Dilep_pixelH_Mu1->Integral();
   float intPixhitsS14Mu2 = h_wjets_PUS14_Dilep_pixelH_Mu2->Integral();
      
   float intPixhits8tevMu1 = h_wjets_8TeV_Dilep_pixelH_Mu1->Integral();
   float intPixhits8tevMu2 = h_wjets_8TeV_Dilep_pixelH_Mu2->Integral();
      

   float eff2025Mu1 [5], eff2025Mu2 [5],  effS14Mu1 [5], effS14Mu2 [5], eff8tevMu1 [5], eff8tevMu2 [5];


   for ( int c = 0; c < NcutPixhits; c++ ) {

     eff2025Mu1 [c] =  (h_wjets_PU20bx25_Dilep_pixelH_Mu1->Integral(c+2, 6))/intPixhits2025Mu1;
     eff2025Mu2 [c] =  (h_wjets_PU20bx25_Dilep_pixelH_Mu2->Integral(c+2, 6))/intPixhits2025Mu2;

     effS14Mu1 [c] =  (h_wjets_PUS14_Dilep_pixelH_Mu1->Integral(c+2, 6))/intPixhitsS14Mu1;
     effS14Mu2 [c] =  (h_wjets_PUS14_Dilep_pixelH_Mu2->Integral(c+2, 6))/intPixhitsS14Mu2;

     eff8tevMu1 [c] =  (h_wjets_8TeV_Dilep_pixelH_Mu1->Integral(c+2, 6))/intPixhits8tevMu1;
     eff8tevMu2 [c] =  (h_wjets_8TeV_Dilep_pixelH_Mu2->Integral(c+2, 6))/intPixhits8tevMu2;

     cout << eff8tevMu1 [c] <<  "  " << eff8tevMu2 [c] << endl;
   }

   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_pixhits = new TGraph(NcutPixhits, eff2025Mu2, eff2025Mu1);
   h_ROC_PU20bx25_Dilep_pixhits->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_pixhits->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_pixhits->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_pixhits->SetMarkerStyle(kFullCircle);
  
   h_ROC_PUS14_Dilep_pixhits = new TGraph(NcutPixhits, effS14Mu2, effS14Mu1);
   h_ROC_PUS14_Dilep_pixhits->SetLineColor(6);
   h_ROC_PUS14_Dilep_pixhits->SetLineWidth(2);
   h_ROC_PUS14_Dilep_pixhits->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_pixhits->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_pixhits = new TGraph(NcutPixhits, eff8tevMu2, eff8tevMu1);
   h_ROC_8tev_Dilep_pixhits->SetLineColor(4);
   h_ROC_8tev_Dilep_pixhits->SetLineWidth(2);
   h_ROC_8tev_Dilep_pixhits->SetMarkerColor(4);
   h_ROC_8tev_Dilep_pixhits->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_pixhits,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_pixhits,"");
   wjets_ROC->Add(h_ROC_PU20bx25_Dilep_pixhits,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("Wjets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("'Fake' muon cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("Prompt muon cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_pixhits , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_pixhits , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_pixhits , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }



if (doROCcurves_STAHits) {


   TGraph *h_ROC_PU20bx25_Dilep_stahits; 
   TGraph *h_ROC_PUS14_Dilep_stahits; 
   TGraph *h_ROC_8tev_Dilep_stahits; 


   int NcutStahits = 11;
   float intStahits2025Mu1 = h_wjets_PU20bx25_Dilep_stahits_Mu1->Integral();
   float intStahits2025Mu2 = h_wjets_PU20bx25_Dilep_stahits_Mu2->Integral();

   float intStahitsS14Mu1 = h_wjets_PUS14_Dilep_stahits_Mu1->Integral();
   float intStahitsS14Mu2 = h_wjets_PUS14_Dilep_stahits_Mu2->Integral();
      
   float intStahits8tevMu1 = h_wjets_8TeV_Dilep_stahits_Mu1->Integral();
   float intStahits8tevMu2 = h_wjets_8TeV_Dilep_stahits_Mu2->Integral();
      

   float eff2025Mu1 [11], eff2025Mu2 [11],  effS14Mu1 [11], effS14Mu2 [11], eff8tevMu1 [11], eff8tevMu2 [11];


   for ( int c = 0; c < NcutStahits; c++ ) {

     eff2025Mu1 [c] =  (h_wjets_PU20bx25_Dilep_stahits_Mu1->Integral(c+2, 50))/intStahits2025Mu1;
     eff2025Mu2 [c] =  (h_wjets_PU20bx25_Dilep_stahits_Mu2->Integral(c+2, 50))/intStahits2025Mu2;

     effS14Mu1 [c] =  (h_wjets_PUS14_Dilep_stahits_Mu1->Integral(c+2, 50))/intStahitsS14Mu1;
     effS14Mu2 [c] =  (h_wjets_PUS14_Dilep_stahits_Mu2->Integral(c+2, 50))/intStahitsS14Mu2;

     eff8tevMu1 [c] =  (h_wjets_8TeV_Dilep_stahits_Mu1->Integral(c+2, 50))/intStahits8tevMu1;
     eff8tevMu2 [c] =  (h_wjets_8TeV_Dilep_stahits_Mu2->Integral(c+2, 50))/intStahits8tevMu2;

     cout << eff8tevMu1 [c] <<  "  " << eff8tevMu2 [c] << endl;
   }

   TCanvas *c1 = new TCanvas("c1", "", 800, 800);

   c1->cd();

   TMultiGraph *wjets_ROC = new TMultiGraph();
   
   h_ROC_PU20bx25_Dilep_stahits = new TGraph(NcutStahits, eff2025Mu2, eff2025Mu1);
   h_ROC_PU20bx25_Dilep_stahits->SetLineColor(7);
   h_ROC_PU20bx25_Dilep_stahits->SetLineWidth(2);
   h_ROC_PU20bx25_Dilep_stahits->SetMarkerColor(7);
   h_ROC_PU20bx25_Dilep_stahits->SetMarkerStyle(kFullCircle);
  
   h_ROC_PUS14_Dilep_stahits = new TGraph(NcutStahits, effS14Mu2, effS14Mu1);
   h_ROC_PUS14_Dilep_stahits->SetLineColor(6);
   h_ROC_PUS14_Dilep_stahits->SetLineWidth(2);
   h_ROC_PUS14_Dilep_stahits->SetMarkerColor(6);
   h_ROC_PUS14_Dilep_stahits->SetMarkerStyle(kFullCircle);
   
   h_ROC_8tev_Dilep_stahits = new TGraph(NcutStahits, eff8tevMu2, eff8tevMu1);
   h_ROC_8tev_Dilep_stahits->SetLineColor(4);
   h_ROC_8tev_Dilep_stahits->SetLineWidth(2);
   h_ROC_8tev_Dilep_stahits->SetMarkerColor(4);
   h_ROC_8tev_Dilep_stahits->SetMarkerStyle(kFullCircle);
 
   
   wjets_ROC->Add(h_ROC_8tev_Dilep_stahits,"");
   wjets_ROC->Add(h_ROC_PUS14_Dilep_stahits,"");
   wjets_ROC->Add(h_ROC_PU20bx25_Dilep_stahits,"");
   wjets_ROC->Draw("ALP");
 
   wjets_ROC->SetTitle("Wjets dilepton sample");
   wjets_ROC->GetXaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleSize(0.04);
   wjets_ROC->GetYaxis()->SetTitleOffset(1.8);
   wjets_ROC->GetXaxis()->SetTitle("'Fake' muon cut efficiency ");
   wjets_ROC->GetYaxis()->SetTitle("Prompt muon cut efficiency ");

   DrawLegendG(0.65,0.40,h_ROC_8tev_Dilep_stahits , "8TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.35,h_ROC_PUS14_Dilep_stahits , "13TeV, 50ns ", "LP",0.020,0.12, 0.10);
   DrawLegendG(0.65,0.30,h_ROC_PU20bx25_Dilep_stahits , "13TeV, 25ns ", "LP",0.020,0.12, 0.10);

 }



 if ( doHWWPFIso) {


 TCanvas *hww_PFIso_Mu1 = new TCanvas("hww_PFIso_Mu1", "Hww PFIso Leading Lepton", 750, 750);
 
 // hww_chi2->Divide(2,1);
 
 hww_PFIso_Mu1->cd();

 float float1 = h_hww_8TeV_Dilep_PFIso_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_PFIso_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_PFIso_Mu1->Integral();

 h_hww_8TeV_Dilep_PFIso_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_PFIso_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_PFIso_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_PFIso_Mu1,h_hww_8TeV_Dilep_PFIso_Mu1 ,"hist","","REl. PF isolation / pt (deltaBeta)","#events");
 LineOpt(h_hww_8TeV_Dilep_PFIso_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_PFIso_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_PFIso_Mu1,h_hww_PUS14_Dilep_PFIso_Mu1, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_PFIso_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_PFIso_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_PFIso_Mu1,h_hww_PU20bx25_Dilep_PFIso_Mu1, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_PFIso_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_PFIso_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_PFIso_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_PFIso_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_PFIso_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *hww_PFIso_Mu2 = new TCanvas("hww_PFIso_Mu2", "Hww PFIso SubLeading Lepton", 750, 750);
 
 // hww_chi2->Divide(2,1);
 
 hww_PFIso_Mu2->cd();

 float float1 = h_hww_8TeV_Dilep_PFIso_Mu2->Integral();
 float float2 = h_hww_PUS14_Dilep_PFIso_Mu2->Integral();
 float float3 = h_hww_PU20bx25_Dilep_PFIso_Mu2->Integral();

 h_hww_8TeV_Dilep_PFIso_Mu2->Scale(1.0/float1);
 h_hww_PUS14_Dilep_PFIso_Mu2->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_PFIso_Mu2->Scale(1.0/float3);
 

 DrawTH1F(hww_PFIso_Mu2,h_hww_8TeV_Dilep_PFIso_Mu2 ,"hist","","REl. PF isolation / pt (deltaBeta)","#events");
 LineOpt(h_hww_8TeV_Dilep_PFIso_Mu2,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_PFIso_Mu2,4,1,kFullCircle);
 
 DrawTH1F(hww_PFIso_Mu2,h_hww_PUS14_Dilep_PFIso_Mu2, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_PFIso_Mu2,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_PFIso_Mu2,6,1,kFullCircle);
 
 DrawTH1F(hww_PFIso_Mu2,h_hww_PU20bx25_Dilep_PFIso_Mu2, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_PFIso_Mu2,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_PFIso_Mu2,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_PFIso_Mu2, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_PFIso_Mu2 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_PFIso_Mu2, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 }



 if (doHWW) {

// ----> Compare HWW samples 





 TCanvas *hww_chi2 = new TCanvas("hww_chi2", "Hww Chi2 Leading Lepton", 750, 750);
 
 // hww_chi2->Divide(2,1);
 
 hww_chi2->cd();

 float float1 = h_hww_8TeV_Dilep_chi2_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_chi2_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_chi2_Mu1->Integral();

 h_hww_8TeV_Dilep_chi2_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_chi2_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_chi2_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_chi2,h_hww_8TeV_Dilep_chi2_Mu1 ,"hist","","Chi2/n.d.o.f.","#events");
 LineOpt(h_hww_8TeV_Dilep_chi2_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_chi2_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_chi2,h_hww_PUS14_Dilep_chi2_Mu1, "histsame","","Chi2/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_chi2_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_chi2_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_chi2,h_hww_PU20bx25_Dilep_chi2_Mu1, "histsame","","Chi2/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_chi2_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_chi2_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_chi2_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_chi2_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_chi2_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 TCanvas *hww_stahits = new TCanvas("hww_stahits", "Hww #STA Hits Leading lepton", 750, 750);
 
 //hww_stahits->Divide(2,1);
 
 hww_stahits->cd();

  float float1 = h_hww_8TeV_Dilep_stahits_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_stahits_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_stahits_Mu1->Integral();

 h_hww_8TeV_Dilep_stahits_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_stahits_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_stahits_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_stahits,h_hww_8TeV_Dilep_stahits_Mu1 ,"hist","","#STA Hits","#events");
 LineOpt(h_hww_8TeV_Dilep_stahits_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_stahits_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_stahits,h_hww_PUS14_Dilep_stahits_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_stahits_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_stahits_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_stahits,h_hww_PU20bx25_Dilep_stahits_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_stahits_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_stahits_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_stahits_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_stahits_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_stahits_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 TCanvas *hww_nsta = new TCanvas("hww_nsta", "Hww #Matched Stations Leading lepton", 750, 750);
 
 //hww_nsta->Divide(2,1);
 
 hww_nsta->cd();

 float float1 = h_hww_8TeV_Dilep_nsta_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_nsta_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_nsta_Mu1->Integral();

 h_hww_8TeV_Dilep_nsta_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_nsta_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_nsta_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_nsta,h_hww_8TeV_Dilep_nsta_Mu1 ,"hist","","#Matched stations","#events");
 LineOpt(h_hww_8TeV_Dilep_nsta_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_nsta_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_nsta,h_hww_PUS14_Dilep_nsta_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_nsta_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_nsta_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_nsta,h_hww_PU20bx25_Dilep_nsta_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_nsta_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_nsta_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_nsta_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_nsta_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_nsta_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 TCanvas *hww_pixelH = new TCanvas("hww_pixelH", "Hww #Pixel Hits Leading lepton", 750, 750);
 
 //hww_pixelH->Divide(2,1);
 
 hww_pixelH->cd();

 float float1 = h_hww_8TeV_Dilep_pixelH_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_pixelH_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_pixelH_Mu1->Integral();

 h_hww_8TeV_Dilep_pixelH_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_pixelH_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_pixelH_Mu1->Scale(1.0/float3);
 
 DrawTH1F(hww_pixelH,h_hww_8TeV_Dilep_pixelH_Mu1 ,"hist","","# Pixel Hits","#events");
 LineOpt(h_hww_8TeV_Dilep_pixelH_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_pixelH_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_pixelH,h_hww_PUS14_Dilep_pixelH_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_pixelH_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_pixelH_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_pixelH,h_hww_PU20bx25_Dilep_pixelH_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_pixelH_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_pixelH_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_pixelH_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_pixelH_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_pixelH_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *hww_tkL = new TCanvas("hww_tkL", "Hww #TK Layers Leading lepton", 750, 750);
 
 //hww_tkL->Divide(2,1);
 
 hww_tkL->cd();

  float float1 = h_hww_8TeV_Dilep_tkL_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_tkL_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_tkL_Mu1->Integral();

 h_hww_8TeV_Dilep_tkL_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_tkL_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_tkL_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_tkL,h_hww_8TeV_Dilep_tkL_Mu1 ,"hist","","# TK Layers","#events");
 LineOpt(h_hww_8TeV_Dilep_tkL_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_tkL_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_tkL,h_hww_PUS14_Dilep_tkL_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_tkL_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_tkL_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_tkL,h_hww_PU20bx25_Dilep_tkL_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_tkL_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_tkL_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_tkL_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_tkL_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_tkL_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *hww_dxy = new TCanvas("hww_dxy", "Hww dxy wrt PV Leading lepton", 750, 750);
 
 //hww_dxy->Divide(2,1);
 
 hww_dxy->cd();

 float float1 = h_hww_8TeV_Dilep_dxy_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_dxy_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_dxy_Mu1->Integral();

 h_hww_8TeV_Dilep_dxy_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_dxy_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_dxy_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_dxy,h_hww_8TeV_Dilep_dxy_Mu1 ,"hist","","dxy wrt PV","#events");
 LineOpt(h_hww_8TeV_Dilep_dxy_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_dxy_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_dxy,h_hww_PUS14_Dilep_dxy_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_dxy_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_dxy_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_dxy,h_hww_PU20bx25_Dilep_dxy_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_dxy_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_dxy_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_dxy_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_dxy_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_dxy_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *hww_dz = new TCanvas("hww_dz", "Hww dz wrt PV Leading lepton", 750, 750);
 
 //hww_dz->Divide(2,1);
 
 hww_dz->cd();

  float float1 = h_hww_8TeV_Dilep_dz_Mu1->Integral();
 float float2 = h_hww_PUS14_Dilep_dz_Mu1->Integral();
 float float3 = h_hww_PU20bx25_Dilep_dz_Mu1->Integral();

 h_hww_8TeV_Dilep_dz_Mu1->Scale(1.0/float1);
 h_hww_PUS14_Dilep_dz_Mu1->Scale(1.0/float2);
 h_hww_PU20bx25_Dilep_dz_Mu1->Scale(1.0/float3);
 

 DrawTH1F(hww_dz,h_hww_8TeV_Dilep_dz_Mu1 ,"hist","","dz wrt PV","#events");
 LineOpt(h_hww_8TeV_Dilep_dz_Mu1,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_dz_Mu1,4,1,kFullCircle);
 
 DrawTH1F(hww_dz,h_hww_PUS14_Dilep_dz_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_dz_Mu1,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_dz_Mu1,6,1,kFullCircle);
 
 DrawTH1F(hww_dz,h_hww_PU20bx25_Dilep_dz_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_dz_Mu1,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_dz_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_hww_8TeV_Dilep_dz_Mu1, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_dz_Mu1 , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_dz_Mu1, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


}  // END HWW 



 if (doWjets) {

// ----> Compare WJETS samples 


 TCanvas *wjets_chi2 = new TCanvas("wjets_chi2", "Wjets Chi2 Leading Lepton", 750, 750);
 
 // wjets_chi2->Divide(2,1);
 
 wjets_chi2->cd();

 float float1 = h_wjets_8TeV_Dilep_chi2_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_chi2_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_chi2_Mu1->Integral();

 h_wjets_8TeV_Dilep_chi2_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_chi2_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_chi2_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_chi2,h_wjets_8TeV_Dilep_chi2_Mu1 ,"hist","","Chi2/n.d.o.f.","#events");
 LineOpt(h_wjets_8TeV_Dilep_chi2_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_chi2_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_chi2,h_wjets_PUS14_Dilep_chi2_Mu1, "histsame","","Chi2/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_chi2_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_chi2_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_chi2,h_wjets_PU20bx25_Dilep_chi2_Mu1, "histsame","","Chi2/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_chi2_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_chi2_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_chi2_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_chi2_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_chi2_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 TCanvas *wjets_stahits = new TCanvas("wjets_stahits", "Wjets #STA Hits Leading lepton", 750, 750);
 
 //wjets_stahits->Divide(2,1);
 
 wjets_stahits->cd();

  float float1 = h_wjets_8TeV_Dilep_stahits_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_stahits_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_stahits_Mu1->Integral();

 h_wjets_8TeV_Dilep_stahits_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_stahits_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_stahits_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_stahits,h_wjets_8TeV_Dilep_stahits_Mu1 ,"hist","","#STA Hits","#events");
 LineOpt(h_wjets_8TeV_Dilep_stahits_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_stahits_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_stahits,h_wjets_PUS14_Dilep_stahits_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_stahits_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_stahits_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_stahits,h_wjets_PU20bx25_Dilep_stahits_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_stahits_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_stahits_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_stahits_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_stahits_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_stahits_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


TCanvas *wjets_stahitsEta = new TCanvas("wjets_stahitsEta", "Wjets #STA Hits vs Eta Leading lepton", 750, 750);
 
 //wjets_stahitsEta->Divide(2,1);
 
 wjets_stahitsEta->cd();

 TH1D *h1 = h_wjets_8TeV_Dilep_stahitsEta_Mu1->ProfileX()->ProjectionX();
 TH1D *h2 = h_wjets_PUS14_Dilep_stahitsEta_Mu1->ProfileX()->ProjectionX();
 TH1D *h3 = h_wjets_PU20bx25_Dilep_stahitsEta_Mu1->ProfileX()->ProjectionX();


 DrawTH1F(wjets_stahitsEta, h1,"hist","","Eta","#STA hits");
 LineOpt(h1,4,2,kSolid);
 MarkerOpt(h1,4,1,kFullCircle);
 
 DrawTH1F(wjets_stahitsEta,h2, "same","","TkL/n.d.o.f.","#events");
 LineOpt(h2,6,2,kSolid);
 MarkerOpt(h2,6,1,kFullCircle);

 DrawTH1F(wjets_stahitsEta,h3, "same","","TkL/n.d.o.f.","#events");
 LineOpt(h3,7,2,kSolid);
 MarkerOpt(h3,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h2, "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h3, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


TCanvas *wjets_stahitsPV = new TCanvas("wjets_stahitsPV", "Wjets #STA Hits vs PV Leading lepton", 750, 750);
 
 //wjets_stahitsPV->Divide(2,1);
 
 wjets_stahitsPV->cd();

 TH1D *h1 = h_wjets_8TeV_Dilep_stahitsPV_Mu1->ProfileX()->ProjectionX();
 TH1D *h2 = h_wjets_PUS14_Dilep_stahitsPV_Mu1->ProfileX()->ProjectionX();
 TH1D *h3 = h_wjets_PU20bx25_Dilep_stahitsPV_Mu1->ProfileX()->ProjectionX();

 DrawTH1F(wjets_stahitsPV, h1,"hist","","PV","#STA hits");
 LineOpt(h1,4,2,kSolid);
 MarkerOpt(h1,4,1,kFullCircle);
 
 DrawTH1F(wjets_stahitsPV,h2, "same","","TkL/n.d.o.f.","#events");
 LineOpt(h2,6,2,kSolid);
 MarkerOpt(h2,6,1,kFullCircle);

 DrawTH1F(wjets_stahitsPV,h3, "same","","TkL/n.d.o.f.","#events");
 LineOpt(h3,7,2,kSolid);
 MarkerOpt(h3,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h2, "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h3, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);





 TCanvas *wjets_nsta = new TCanvas("wjets_nsta", "Wjets #Matched stations Leading lepton", 750, 750);
 
 //wjets_nsta->Divide(2,1);
 
 wjets_nsta->cd();

 float float1 = h_wjets_8TeV_Dilep_nsta_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_nsta_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_nsta_Mu1->Integral();

 h_wjets_8TeV_Dilep_nsta_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_nsta_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_nsta_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_nsta,h_wjets_8TeV_Dilep_nsta_Mu1 ,"hist","","#Matched stations","#events");
 LineOpt(h_wjets_8TeV_Dilep_nsta_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_nsta_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_nsta,h_wjets_PUS14_Dilep_nsta_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_nsta_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_nsta_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_nsta,h_wjets_PU20bx25_Dilep_nsta_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_nsta_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_nsta_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_nsta_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_nsta_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_nsta_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


 TCanvas *wjets_pixelH = new TCanvas("wjets_pixelH", "Wjets #Pixel Hits Leading lepton", 750, 750);
 
 //wjets_pixelH->Divide(2,1);
 
 wjets_pixelH->cd();

 float float1 = h_wjets_8TeV_Dilep_pixelH_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_pixelH_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_pixelH_Mu1->Integral();

 h_wjets_8TeV_Dilep_pixelH_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_pixelH_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_pixelH_Mu1->Scale(1.0/float3);
 
 DrawTH1F(wjets_pixelH,h_wjets_8TeV_Dilep_pixelH_Mu1 ,"hist","","# Pixel Hits","#events");
 LineOpt(h_wjets_8TeV_Dilep_pixelH_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_pixelH_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_pixelH,h_wjets_PUS14_Dilep_pixelH_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_pixelH_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_pixelH_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_pixelH,h_wjets_PU20bx25_Dilep_pixelH_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_pixelH_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_pixelH_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_pixelH_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_pixelH_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_pixelH_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *wjets_tkL = new TCanvas("wjets_tkL", "Wjets #TK Layers Leading lepton", 750, 750);
 
 //wjets_tkL->Divide(2,1);
 
 wjets_tkL->cd();

  float float1 = h_wjets_8TeV_Dilep_tkL_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_tkL_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_tkL_Mu1->Integral();

 h_wjets_8TeV_Dilep_tkL_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_tkL_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_tkL_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_tkL,h_wjets_8TeV_Dilep_tkL_Mu1 ,"hist","","# TK Layers","#events");
 LineOpt(h_wjets_8TeV_Dilep_tkL_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_tkL_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_tkL,h_wjets_PUS14_Dilep_tkL_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_tkL_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_tkL_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_tkL,h_wjets_PU20bx25_Dilep_tkL_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_tkL_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_tkL_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_tkL_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_tkL_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_tkL_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *wjets_dxy = new TCanvas("wjets_dxy", "Wjets dxy wrt PV Leading lepton", 750, 750);
 
 //wjets_dxy->Divide(2,1);
 
 wjets_dxy->cd();

 float float1 = h_wjets_8TeV_Dilep_dxy_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_dxy_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_dxy_Mu1->Integral();

 h_wjets_8TeV_Dilep_dxy_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_dxy_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_dxy_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_dxy,h_wjets_8TeV_Dilep_dxy_Mu1 ,"hist","","dxy wrt PV","#events");
 LineOpt(h_wjets_8TeV_Dilep_dxy_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_dxy_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_dxy,h_wjets_PUS14_Dilep_dxy_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_dxy_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_dxy_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_dxy,h_wjets_PU20bx25_Dilep_dxy_Mu1, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_dxy_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_dxy_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_dxy_Mu1, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_dxy_Mu1 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_dxy_Mu1, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *wjets_dz = new TCanvas("wjets_dz", "Wjets dz wrt PV SubLeading lepton", 750, 750);
 
 //wjets_dz->Divide(2,1);
 
 wjets_dz->cd();

  float float1 = h_wjets_8TeV_Dilep_dz_Mu2->Integral();
 float float2 = h_wjets_PUS14_Dilep_dz_Mu2->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_dz_Mu2->Integral();

 h_wjets_8TeV_Dilep_dz_Mu2->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_dz_Mu2->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_dz_Mu2->Scale(1.0/float3);
 

 DrawTH1F(wjets_dz,h_wjets_8TeV_Dilep_dz_Mu2 ,"hist","","dz wrt PV","#events");
 LineOpt(h_wjets_8TeV_Dilep_dz_Mu2,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_dz_Mu2,4,1,kFullCircle);
 
 DrawTH1F(wjets_dz,h_wjets_PUS14_Dilep_dz_Mu2, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_dz_Mu2,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_dz_Mu2,6,1,kFullCircle);
 
 DrawTH1F(wjets_dz,h_wjets_PU20bx25_Dilep_dz_Mu2, "E1same","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_dz_Mu2,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_dz_Mu2,7,1,kFullCircle);
 
 DrawLegend(0.25,0.80, h_wjets_8TeV_Dilep_dz_Mu2, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_wjets_PUS14_Dilep_dz_Mu2 , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_wjets_PU20bx25_Dilep_dz_Mu2, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


}  // END WJets 


 if (doHWWEff) {


 TCanvas *hww_Eff_Mu1 = new TCanvas("hww_Eff_Mu1", "Hww relative efficiency Leading lepton", 750, 750);
 hww_Eff_Mu1->cd();

 float firstBin8tev = h_hww_8TeV_Dilep_Eff_Mu1->GetBinContent(1);
 float firstBinS14 = h_hww_PUS14_Dilep_Eff_Mu1->GetBinContent(1);
 float firstBin2025 = h_hww_PU20bx25_Dilep_Eff_Mu1->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_hww_8TeV_Dilep_Eff_Mu1->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_hww_8TeV_Dilep_Eff_Mu1_norm->SetBinContent(i, normBin8tev) ;

   float binS14 = h_hww_PUS14_Dilep_Eff_Mu1->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_hww_PUS14_Dilep_Eff_Mu1_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_hww_PU20bx25_Dilep_Eff_Mu1->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_hww_PU20bx25_Dilep_Eff_Mu1_norm->SetBinContent(i, normBin2025) ;

 cout << normBin8tev << "  "  << normBinS14 << "  " << normBin2025 << endl;

 }


 DrawTH1F(hww_Eff_Mu1,h_hww_8TeV_Dilep_Eff_Mu1_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_Dilep_Eff_Mu1_norm,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_Eff_Mu1_norm,4,1,kFullCircle);
 
 DrawTH1F(hww_Eff_Mu1,h_hww_PUS14_Dilep_Eff_Mu1_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_Eff_Mu1_norm,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_Eff_Mu1_norm,6,1,kFullCircle);
 
 DrawTH1F(hww_Eff_Mu1,h_hww_PU20bx25_Dilep_Eff_Mu1_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_Eff_Mu1_norm,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_Eff_Mu1_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_Eff_Mu1_norm, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_Eff_Mu1_norm , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_Eff_Mu1_norm, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


TCanvas *hww_Eff_Mu2 = new TCanvas("hww_Eff_Mu2", "Hww relative efficiency Subleading lepton", 750, 750);
 hww_Eff_Mu2->cd();

 float firstBin8tev = h_hww_8TeV_Dilep_Eff_Mu2->GetBinContent(1);
 float firstBinS14 = h_hww_PUS14_Dilep_Eff_Mu2->GetBinContent(1);
 float firstBin2025 = h_hww_PU20bx25_Dilep_Eff_Mu2->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_hww_8TeV_Dilep_Eff_Mu2->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_hww_8TeV_Dilep_Eff_Mu2_norm->SetBinContent(i, normBin8tev) ;

   float binS14 = h_hww_PUS14_Dilep_Eff_Mu2->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_hww_PUS14_Dilep_Eff_Mu2_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_hww_PU20bx25_Dilep_Eff_Mu2->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_hww_PU20bx25_Dilep_Eff_Mu2_norm->SetBinContent(i, normBin2025) ;


   cout << normBin8tev << "  "  << normBinS14 << "  " << normBin2025 << endl;

 }


 DrawTH1F(hww_Eff_Mu2,h_hww_8TeV_Dilep_Eff_Mu2_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_Dilep_Eff_Mu2_norm,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_Eff_Mu2_norm,4,1,kFullCircle);
 
 DrawTH1F(hww_Eff_Mu2,h_hww_PUS14_Dilep_Eff_Mu2_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_Eff_Mu2_norm,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_Eff_Mu2_norm,6,1,kFullCircle);
 
 DrawTH1F(hww_Eff_Mu2,h_hww_PU20bx25_Dilep_Eff_Mu2_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_Eff_Mu2_norm,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_Eff_Mu2_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_Eff_Mu2_norm, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_Eff_Mu2_norm , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_Eff_Mu2_norm, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 
 }

   


 if (doWjetsEff) {

 TCanvas *wjets_Eff_Mu1 = new TCanvas("wjets_Eff_Mu1", "Wjets relative efficiency Leading lepton", 750, 750);
 wjets_Eff_Mu1->cd();

 float firstBin8tev = h_wjets_8TeV_Dilep_Eff_Mu1->GetBinContent(1);
 float firstBinS14 = h_wjets_PUS14_Dilep_Eff_Mu1->GetBinContent(1);
 float firstBin2025 = h_wjets_PU20bx25_Dilep_Eff_Mu1->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_wjets_8TeV_Dilep_Eff_Mu1->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_wjets_8TeV_Dilep_Eff_Mu1_norm->SetBinContent(i, normBin8tev) ;

   float binS14 = h_wjets_PUS14_Dilep_Eff_Mu1->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_wjets_PUS14_Dilep_Eff_Mu1_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_wjets_PU20bx25_Dilep_Eff_Mu1->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_wjets_PU20bx25_Dilep_Eff_Mu1_norm->SetBinContent(i, normBin2025) ;

 cout << normBin8tev << "  "  << normBinS14 << "  " << normBin2025 << endl;


 }


 DrawTH1F(wjets_Eff_Mu1,h_wjets_8TeV_Dilep_Eff_Mu1_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_wjets_8TeV_Dilep_Eff_Mu1_norm,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_Eff_Mu1_norm,4,1,kFullCircle);
 
 DrawTH1F(wjets_Eff_Mu1,h_wjets_PUS14_Dilep_Eff_Mu1_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_Eff_Mu1_norm,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_Eff_Mu1_norm,6,1,kFullCircle);
 
 DrawTH1F(wjets_Eff_Mu1,h_wjets_PU20bx25_Dilep_Eff_Mu1_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_Eff_Mu1_norm,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_Eff_Mu1_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_Eff_Mu1_norm, "WJets 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_Eff_Mu1_norm , "WJets 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_Eff_Mu1_norm, "WJets 13TeV, 25ns ", "LP",0.020,0.12, 0.10);


TCanvas *wjets_Eff_Mu2 = new TCanvas("wjets_Eff_Mu2", "Wjets relative efficiency Subleading lepton", 750, 750);
 wjets_Eff_Mu2->cd();

 float firstBin8tev = h_wjets_8TeV_Dilep_Eff_Mu2->GetBinContent(1);
 float firstBinS14 = h_wjets_PUS14_Dilep_Eff_Mu2->GetBinContent(1);
 float firstBin2025 = h_wjets_PU20bx25_Dilep_Eff_Mu2->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_wjets_8TeV_Dilep_Eff_Mu2->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_wjets_8TeV_Dilep_Eff_Mu2_norm->SetBinContent(i, normBin8tev) ;

   float binS14 = h_wjets_PUS14_Dilep_Eff_Mu2->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_wjets_PUS14_Dilep_Eff_Mu2_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_wjets_PU20bx25_Dilep_Eff_Mu2->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_wjets_PU20bx25_Dilep_Eff_Mu2_norm->SetBinContent(i, normBin2025) ;

   cout << normBin8tev << "  "  << normBinS14 << "  " << normBin2025 << endl;


 }


 DrawTH1F(wjets_Eff_Mu2,h_wjets_8TeV_Dilep_Eff_Mu2_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_wjets_8TeV_Dilep_Eff_Mu2_norm,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_Eff_Mu2_norm,4,1,kFullCircle);
 
 DrawTH1F(wjets_Eff_Mu2,h_wjets_PUS14_Dilep_Eff_Mu2_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_Eff_Mu2_norm,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_Eff_Mu2_norm,6,1,kFullCircle);
 
 DrawTH1F(wjets_Eff_Mu2,h_wjets_PU20bx25_Dilep_Eff_Mu2_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_Eff_Mu2_norm,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_Eff_Mu2_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_Eff_Mu2_norm, "WJets 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_Eff_Mu2_norm , "WJets 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_Eff_Mu2_norm, "WJets 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 
 }




 if ( doWjetsPFIso) {


 TCanvas *wjets_PFIso_Mu1 = new TCanvas("wjets_PFIso_Mu1", "WJets PFIso Leading Lepton", 750, 750);
 
 // hww_chi2->Divide(2,1);
 
 wjets_PFIso_Mu1->cd();

 float float1 = h_wjets_8TeV_Dilep_PFIso_Mu1->Integral();
 float float2 = h_wjets_PUS14_Dilep_PFIso_Mu1->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_PFIso_Mu1->Integral();

 h_wjets_8TeV_Dilep_PFIso_Mu1->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_PFIso_Mu1->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_PFIso_Mu1->Scale(1.0/float3);
 

 DrawTH1F(wjets_PFIso_Mu1,h_wjets_8TeV_Dilep_PFIso_Mu1 ,"hist","","REl. PF isolation / pt (deltaBeta)","#events");
 LineOpt(h_wjets_8TeV_Dilep_PFIso_Mu1,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_PFIso_Mu1,4,1,kFullCircle);
 
 DrawTH1F(wjets_PFIso_Mu1,h_wjets_PUS14_Dilep_PFIso_Mu1, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_PFIso_Mu1,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_PFIso_Mu1,6,1,kFullCircle);
 
 DrawTH1F(wjets_PFIso_Mu1,h_wjets_PU20bx25_Dilep_PFIso_Mu1, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_PFIso_Mu1,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_PFIso_Mu1,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_PFIso_Mu1, "WJets 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_PFIso_Mu1 , "WJets 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_PFIso_Mu1, "WJets 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *wjets_PFIso_Mu2 = new TCanvas("wjets_PFIso_Mu2", "Wjets PFIso 'fake' Lepton", 750, 750);
 
 // wjets_chi2->Divide(2,1);
 
 wjets_PFIso_Mu2->cd();

 float float1 = h_wjets_8TeV_Dilep_PFIso_Mu2->Integral();
 float float2 = h_wjets_PUS14_Dilep_PFIso_Mu2->Integral();
 float float3 = h_wjets_PU20bx25_Dilep_PFIso_Mu2->Integral();

 h_wjets_8TeV_Dilep_PFIso_Mu2->Scale(1.0/float1);
 h_wjets_PUS14_Dilep_PFIso_Mu2->Scale(1.0/float2);
 h_wjets_PU20bx25_Dilep_PFIso_Mu2->Scale(1.0/float3);
 

 DrawTH1F(wjets_PFIso_Mu2,h_wjets_8TeV_Dilep_PFIso_Mu2 ,"hist","","REl. PF isolation / pt (deltaBeta)","#events");
 LineOpt(h_wjets_8TeV_Dilep_PFIso_Mu2,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_PFIso_Mu2,4,1,kFullCircle);
 
 DrawTH1F(wjets_PFIso_Mu2,h_wjets_PUS14_Dilep_PFIso_Mu2, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_PFIso_Mu2,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_PFIso_Mu2,6,1,kFullCircle);
 
 DrawTH1F(wjets_PFIso_Mu2,h_wjets_PU20bx25_Dilep_PFIso_Mu2, "histsame","","PFIso/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_PFIso_Mu2,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_PFIso_Mu2,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_PFIso_Mu2, "WJets 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_PFIso_Mu2 , "WJets 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_PFIso_Mu2, "WJets 13TeV, 25ns ", "LP",0.020,0.12, 0.10);







 }


 if (doHWWTuneMuIDEff) {

 TCanvas *hww_Dilep_TigtMuCuts = new TCanvas("hww_Dilep_TigtMuCuts", "HWW Dilep TightMuID", 750, 750);
 hww_Dilep_TigtMuCuts->cd();

 float firstBin8tev = h_hww_8TeV_Dilep_TigtMuCuts->GetBinContent(1);
 // float firstBinS14 = h_hww_PUS14_Dilep_TigtMuCuts->GetBinContent(1);
 //float firstBin2025 = h_hww_PU20bx25_Dilep_TigtMuCuts->GetBinContent(1);


 for ( int i = 1; i < 10; i++ ) {

   float bin8tev = h_hww_8TeV_Dilep_TigtMuCuts->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_hww_8TeV_Dilep_TigtMuCuts_norm->SetBinContent(i, normBin8tev) ;

   /*   float binS14 = h_hww_PUS14_Dilep_TigtMuCuts->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_hww_PUS14_Dilep_TigtMuCuts_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_hww_PU20bx25_Dilep_TigtMuCuts->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_hww_PU20bx25_Dilep_TigtMuCuts_norm->SetBinContent(i, normBin2025) ;
   */ 
}


 DrawTH1F(hww_Dilep_TigtMuCuts,h_hww_8TeV_Dilep_TigtMuCuts_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_Dilep_TigtMuCuts_norm,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_TigtMuCuts_norm,4,1,kFullCircle);
 
 /* DrawTH1F(hww_Dilep_TigtMuCuts,h_hww_PUS14_Dilep_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_TigtMuCuts_norm,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_TigtMuCuts_norm,6,1,kFullCircle);
 
 DrawTH1F(hww_Dilep_TigtMuCuts,h_hww_PU20bx25_Dilep_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_TigtMuCuts_norm,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_TigtMuCuts_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_Dilep_TigtMuCuts_norm, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_Dilep_TigtMuCuts_norm , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_Dilep_TigtMuCuts_norm, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);
 */


 TCanvas *hww_WWlevel_TigtMuCuts = new TCanvas("hww_WWlevel_TigtMuCuts", "HWW WWlevel TightMuID", 750, 750);
 hww_WWlevel_TigtMuCuts->cd();

 float firstBin8tev = h_hww_8TeV_WWlevel_TigtMuCuts->GetBinContent(1);
 // float firstBinS14 = h_hww_PUS14_WWlevel_TigtMuCuts->GetBinContent(1);
 //float firstBin2025 = h_hww_PU20bx25_WWlevel_TigtMuCuts->GetBinContent(1);


 for ( int i = 1; i < 10; i++ ) {

   float bin8tev = h_hww_8TeV_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_hww_8TeV_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBin8tev) ;

   /*   float binS14 = h_hww_PUS14_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_hww_PUS14_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_hww_PU20bx25_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_hww_PU20bx25_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBin2025) ;
   */ 
}


 DrawTH1F(hww_WWlevel_TigtMuCuts,h_hww_8TeV_WWlevel_TigtMuCuts_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_WWlevel_TigtMuCuts_norm,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_WWlevel_TigtMuCuts_norm,4,1,kFullCircle);
 
 /* DrawTH1F(hww_WWlevel_TigtMuCuts,h_hww_PUS14_WWlevel_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_WWlevel_TigtMuCuts_norm,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_WWlevel_TigtMuCuts_norm,6,1,kFullCircle);
 
 DrawTH1F(hww_WWlevel_TigtMuCuts,h_hww_PU20bx25_WWlevel_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_WWlevel_TigtMuCuts_norm,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_WWlevel_TigtMuCuts_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_hww_8TeV_WWlevel_TigtMuCuts_norm, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_hww_PUS14_WWlevel_TigtMuCuts_norm , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_hww_PU20bx25_WWlevel_TigtMuCuts_norm, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);
 */
 }



if (doWjetsTuneMuIDEff) {

 TCanvas *wjets_Dilep_TigtMuCuts = new TCanvas("wjets_Dilep_TigtMuCuts", "WJETS Dilep TightMuID", 750, 750);
 wjets_Dilep_TigtMuCuts->cd();

 float firstBin8tev = h_wjets_8TeV_Dilep_TigtMuCuts->GetBinContent(1);
 // float firstBinS14 = h_wjets_PUS14_Dilep_TigtMuCuts->GetBinContent(1);
 //float firstBin2025 = h_wjets_PU20bx25_Dilep_TigtMuCuts->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_wjets_8TeV_Dilep_TigtMuCuts->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_wjets_8TeV_Dilep_TigtMuCuts_norm->SetBinContent(i, normBin8tev) ;

   /*   float binS14 = h_wjets_PUS14_Dilep_TigtMuCuts->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_wjets_PUS14_Dilep_TigtMuCuts_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_wjets_PU20bx25_Dilep_TigtMuCuts->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_wjets_PU20bx25_Dilep_TigtMuCuts_norm->SetBinContent(i, normBin2025) ;
   */ 
}


 DrawTH1F(wjets_Dilep_TigtMuCuts,h_wjets_8TeV_Dilep_TigtMuCuts_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_wjets_8TeV_Dilep_TigtMuCuts_norm,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_Dilep_TigtMuCuts_norm,4,1,kFullCircle);
 
 /* DrawTH1F(wjets_Dilep_TigtMuCuts,h_wjets_PUS14_Dilep_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_Dilep_TigtMuCuts_norm,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_Dilep_TigtMuCuts_norm,6,1,kFullCircle);
 
 DrawTH1F(wjets_Dilep_TigtMuCuts,h_wjets_PU20bx25_Dilep_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_Dilep_TigtMuCuts_norm,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_Dilep_TigtMuCuts_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_Dilep_TigtMuCuts_norm, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_Dilep_TigtMuCuts_norm , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_Dilep_TigtMuCuts_norm, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);
 */


 TCanvas *wjets_WWlevel_TigtMuCuts = new TCanvas("wjets_WWlevel_TigtMuCuts", "WJETS WWlevel TightMuID", 750, 750);
 wjets_WWlevel_TigtMuCuts->cd();

 float firstBin8tev = h_wjets_8TeV_WWlevel_TigtMuCuts->GetBinContent(1);
 // float firstBinS14 = h_wjets_PUS14_WWlevel_TigtMuCuts->GetBinContent(1);
 //float firstBin2025 = h_wjets_PU20bx25_WWlevel_TigtMuCuts->GetBinContent(1);


 for ( int i = 1; i < 9; i++ ) {

   float bin8tev = h_wjets_8TeV_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBin8tev = bin8tev/firstBin8tev; 
   h_wjets_8TeV_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBin8tev) ;

   /*   float binS14 = h_wjets_PUS14_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBinS14 = binS14/firstBinS14; 
   h_wjets_PUS14_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBinS14) ;

   float bin2025 = h_wjets_PU20bx25_WWlevel_TigtMuCuts->GetBinContent(i);
   float normBin2025 = bin2025/firstBin2025; 
   h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm->SetBinContent(i, normBin2025) ;
   */ 
}


 DrawTH1F(wjets_WWlevel_TigtMuCuts,h_wjets_8TeV_WWlevel_TigtMuCuts_norm ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_wjets_8TeV_WWlevel_TigtMuCuts_norm,4,2,kSolid);
 MarkerOpt(h_wjets_8TeV_WWlevel_TigtMuCuts_norm,4,1,kFullCircle);
 
 /* DrawTH1F(wjets_WWlevel_TigtMuCuts,h_wjets_PUS14_WWlevel_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PUS14_WWlevel_TigtMuCuts_norm,6,2,kSolid);
 MarkerOpt(h_wjets_PUS14_WWlevel_TigtMuCuts_norm,6,1,kFullCircle);
 
 DrawTH1F(wjets_WWlevel_TigtMuCuts,h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm,7,2,kSolid);
 MarkerOpt(h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm,7,1,kFullCircle);
 
 DrawLegend(0.65,0.80, h_wjets_8TeV_WWlevel_TigtMuCuts_norm, "WJETS 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.70, h_wjets_PUS14_WWlevel_TigtMuCuts_norm , "WJETS 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.65,0.60, h_wjets_PU20bx25_WWlevel_TigtMuCuts_norm, "WJETS 13TeV, 25ns ", "LP",0.020,0.12, 0.10);
 */
 }



if (doSignalOverBackg) {


 TCanvas *ratio_Dilep_TigtMuCuts = new TCanvas("ratio_Dilep_TigtMuCuts", "Dilep TightMuID Signal/Backg", 750, 750);
 ratio_Dilep_TigtMuCuts->cd();

 h_hww_8TeV_Dilep_TigtMuCuts_ratio->Divide(h_hww_8TeV_Dilep_TigtMuCuts, h_wjets_8TeV_Dilep_TigtMuCuts, 1., 1., "");
 h_hww_PUS14_Dilep_TigtMuCuts_ratio->Divide(h_hww_PUS14_Dilep_TigtMuCuts, h_wjets_PUS14_Dilep_TigtMuCuts, 1., 1., "");
 h_hww_PU20bx25_Dilep_TigtMuCuts_ratio->Divide(h_hww_PU20bx25_Dilep_TigtMuCuts, h_wjets_PU20bx25_Dilep_TigtMuCuts, 1., 1., "");


 DrawTH1F(ratio_Dilep_TigtMuCuts,h_hww_8TeV_Dilep_TigtMuCuts_ratio ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_Dilep_TigtMuCuts_ratio,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_Dilep_TigtMuCuts_ratio,4,1,kFullCircle);
 
 DrawTH1F(ratio_Dilep_TigtMuCuts,h_hww_PUS14_Dilep_TigtMuCuts_ratio, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_Dilep_TigtMuCuts_ratio,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_Dilep_TigtMuCuts_ratio,6,1,kFullCircle);
 
 DrawTH1F(ratio_Dilep_TigtMuCuts,h_hww_PU20bx25_Dilep_TigtMuCuts_ratio, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_Dilep_TigtMuCuts_ratio,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_Dilep_TigtMuCuts_ratio,7,1,kFullCircle);


 DrawLegend(0.25,0.80,h_hww_8TeV_Dilep_TigtMuCuts_ratio, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_Dilep_TigtMuCuts_ratio , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_Dilep_TigtMuCuts_ratio, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);



 TCanvas *ratio_WWlevel_TigtMuCuts = new TCanvas("ratio_WWlevel_TigtMuCuts", "WWlevel TightMuID Signal/Backg", 750, 750);
 ratio_WWlevel_TigtMuCuts->cd();

 h_hww_8TeV_WWlevel_TigtMuCuts_ratio->Divide(h_hww_8TeV_WWlevel_TigtMuCuts, h_wjets_8TeV_WWlevel_TigtMuCuts, 1., 1., "");
 h_hww_PUS14_WWlevel_TigtMuCuts_ratio->Divide(h_hww_PUS14_WWlevel_TigtMuCuts, h_wjets_PUS14_WWlevel_TigtMuCuts, 1., 1., "");
 h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio->Divide(h_hww_PU20bx25_WWlevel_TigtMuCuts, h_wjets_PU20bx25_WWlevel_TigtMuCuts, 1., 1., "");



 DrawTH1F(ratio_WWlevel_TigtMuCuts,h_hww_8TeV_WWlevel_TigtMuCuts_ratio ,"hist","","Tight Mu ID selection efficiency","Relative Efficiency");
 LineOpt(h_hww_8TeV_WWlevel_TigtMuCuts_ratio,4,2,kSolid);
 MarkerOpt(h_hww_8TeV_WWlevel_TigtMuCuts_ratio,4,1,kFullCircle);
 

 DrawTH1F(ratio_WWlevel_TigtMuCuts,h_hww_PUS14_WWlevel_TigtMuCuts_ratio, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PUS14_WWlevel_TigtMuCuts_ratio,6,2,kSolid);
 MarkerOpt(h_hww_PUS14_WWlevel_TigtMuCuts_ratio,6,1,kFullCircle);
 
 DrawTH1F(ratio_WWlevel_TigtMuCuts,h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio, "histsame","","TkL/n.d.o.f.","#events");
 LineOpt(h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio,7,2,kSolid);
 MarkerOpt(h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio,7,1,kFullCircle);


 DrawLegend(0.25,0.80,h_hww_8TeV_WWlevel_TigtMuCuts_ratio, "HWW 8TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.70, h_hww_PUS14_WWlevel_TigtMuCuts_ratio , "HWW 13TeV, 50ns ", "LP",0.020,0.12, 0.10);
 DrawLegend(0.25,0.60, h_hww_PU20bx25_WWlevel_TigtMuCuts_ratio, "HWW 13TeV, 25ns ", "LP",0.020,0.12, 0.10);
 


 }


}
