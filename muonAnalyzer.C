////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/////            Muon Studies for CSA14                     ////

/////        A. Calderón (IFCA)   18 / 08 / 2014            ////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


#include "muonAnalyzer.h"
#include "TH1.h"
#include "TH2.h"
#include "TKey.h"
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TRandom.h"

#include "TLorentzVector.h"
#include <vector>
#include "TROOT.h"
#include <iostream>

#include "TDatabasePDG.h"


muonAnalyzer::muonAnalyzer(TTree* tree):
  PAFAnalysis(tree) {
}


void muonAnalyzer::Initialise() {

  Signal = GetInputParameters()->TheNamedString("Signal");

 
  GetInputParameters()->TheNamedBool("IsDATA", IsDATA);
  GetInputParameters()->TheNamedInt("NEvents", NEvents);
  GetInputParameters()->TheNamedDouble("Luminosity", Luminosity);
  GetInputParameters()->TheNamedDouble("XSection", XSection);
  GetInputParameters()->TheNamedInt("WhichRun", WhichRun);
  
  // To do only once

  float luminosityPU = 0;
  //fInputParameters->TheNamedFloat("luminosityPU",luminosityPU);
  //fPUWeight = new PUWeight(luminosityPU, Spring11);//Summer11InTime);




  G_Debug_DefineAnalysisVariables = false;

 
//------------------------------------------------------------------------------
// Create histos
//------------------------------------------------------------------------------
 

  h_N_PV = CreateH1F ("h_N_PV","h_N_PV",50,0,50); 
  h_N_PV->TH1::SetDefaultSumw2();

  h_N_PV0_PVLep = CreateH1F ("h_N_PV0_PVLep","h_N_PV0_PVLep",20,0,20);
  h_N_dZ_PV0_PVLep = CreateH1F("h_N_dZ_PV0_PVLep", "h_N_dZ_PV0_PVLep", 50,0,1);  

  h_N_Dilep_TypeMu = CreateH1F("h_N_Dilep_TypeMu", "h_N_Dilep_TypeMu", 5,0,5);
  h_N_Dilep_TypeMu_LP = CreateH1F("h_N_Dilep_TypeMu_LP", "h_N_Dilep_TypeMu_LP", 5,0,5);
  h_N_Dilep_TypeMu_HP = CreateH1F("h_N_Dilep_TypeMu_HP", "h_N_Dilep_TypeMu_HP", 5,0,5);
  h_N_WWlevel_TypeMu = CreateH1F("h_N_WWlevel_TypeMu", "h_N_WWlevel_TypeMu", 5,0,5);
  h_N_WWlevel_TypeMu_LP = CreateH1F("h_N_WWlevel_TypeMu_LP", "h_N_WWlevel_TypeMu_LP", 5,0,5);
  h_N_WWlevel_TypeMu_HP = CreateH1F("h_N_WWlevel_TypeMu_HP", "h_N_WWlevel_TypeMu_HP", 5,0,5);


  h_N_Dilep_TigtMuCuts = CreateH1F("h_N_Dilep_TigtMuCuts", "h_N_Dilep_TypeMu_TigtMuCuts", 9,0,9);
  h_N_WWlevel_TigtMuCuts = CreateH1F("h_N_WWlevel_TigtMuCuts", "h_N_WWlevel_TypeMu_TigtMuCuts", 9,0,9);


  h_N_Dilep_TightMuCuts_butTkLayers[0] = CreateH1F("h_N_Dilep_TightMuCuts_butTkLayers_Mu1", "h_N_Dilep_TightMuCuts_butTkLayers_Mu1",20, 0, 20); 
  h_N_Dilep_TightMuCuts_butTkLayers[1] = CreateH1F("h_N_Dilep_TightMuCuts_butTkLayers_Mu2", "h_N_Dilep_TightMuCuts_butTkLayers_Mu2",20, 0, 20);  
  h_N_Dilep_TightMuCuts_butSTAHits[0] = CreateH1F("h_N_Dilep_TightMuCuts_butSTAHits_Mu1", "h_N_Dilep_TightMuCuts_STAHits_Mu1",50, 0, 50);
  h_N_Dilep_TightMuCuts_butSTAHits[1] = CreateH1F("h_N_Dilep_TightMuCuts_butSTAHits_Mu2", "h_N_Dilep_TightMuCuts_STAHits_Mu2",50, 0, 50);

  h_N_WWlevel_TightMuCuts_butTkLayers[0] = CreateH1F("h_N_WWlevel_TightMuCuts_butTkLayers_Mu1", "h_N_WWlevel_TightMuCuts_butTkLayers_Mu1",20, 0, 20); 
  h_N_WWlevel_TightMuCuts_butTkLayers[1] = CreateH1F("h_N_WWlevel_TightMuCuts_butTkLayers_Mu2", "h_N_WWlevel_TightMuCuts_butTkLayers_Mu2",20, 0, 20);  
  h_N_WWlevel_TightMuCuts_butSTAHits[0] = CreateH1F("h_N_WWlevel_TightMuCuts_butSTAHits_Mu1", "h_N_WWlevel_TightMuCuts_STAHits_Mu1",50, 0, 50);
  h_N_WWlevel_TightMuCuts_butSTAHits[1] = CreateH1F("h_N_WWlevel_TightMuCuts_butSTAHits_Mu2", "h_N_WWlevel_TightMuCuts_STAHits_Mu2",50, 0, 50);



  h_N_Dilep_GLBPF_butTkLayers[0] = CreateH1F("h_N_Dilep_GLBPF_butTkLayers_Mu1", "h_N_Dilep_GLBPF_butTkLayers_Mu1",20, 0, 20); 
  h_N_Dilep_GLBPF_butTkLayers[1] = CreateH1F("h_N_Dilep_GLBPF_butTkLayers_Mu2", "h_N_Dilep_GLBPF_butTkLayers_Mu2",20, 0, 20);  
  h_N_Dilep_GLBPF_butSTAHits[0] = CreateH1F("h_N_Dilep_GLBPF_butSTAHits_Mu1", "h_N_Dilep_GLBPF_STAHits_Mu1",50, 0, 50);
  h_N_Dilep_GLBPF_butSTAHits[1] = CreateH1F("h_N_Dilep_GLBPF_butSTAHits_Mu2", "h_N_Dilep_GLBPF_STAHits_Mu2",50, 0, 50);

  h_N_WWlevel_GLBPF_butTkLayers[0] = CreateH1F("h_N_WWlevel_GLBPF_butTkLayers_Mu1", "h_N_WWlevel_GLBPF_butTkLayers_Mu1",20, 0, 20); 
  h_N_WWlevel_GLBPF_butTkLayers[1] = CreateH1F("h_N_WWlevel_GLBPF_butTkLayers_Mu2", "h_N_WWlevel_GLBPF_butTkLayers_Mu2",20, 0, 20);  
  h_N_WWlevel_GLBPF_butSTAHits[0] = CreateH1F("h_N_WWlevel_GLBPF_butSTAHits_Mu1", "h_N_WWlevel_GLBPF_STAHits_Mu1",50, 0, 50);
  h_N_WWlevel_GLBPF_butSTAHits[1] = CreateH1F("h_N_WWlevel_GLBPF_butSTAHits_Mu2", "h_N_WWlevel_GLBPF_STAHits_Mu2",50, 0, 50);



  h_Dilep_AllMu_PFIsoBeta_Mu1 =   CreateH1F("h_Dilep_AllMu_PFIsoBeta_Mu1", "h_Dilep_AllMu_PFIsoBeta_Mu1", 50, 0,1);
  h_Dilep_AllMu_PFIsoBeta_Mu2 =   CreateH1F("h_Dilep_AllMu_PFIsoBeta_Mu2", "h_Dilep_AllMu_PFIsoBeta_Mu2", 50, 0,1);  
  h_Dilep_HWWMu_PFIsoBeta_Mu1 =   CreateH1F("h_Dilep_HWWMu_PFIsoBeta_Mu1", "h_Dilep_HWWMu_PFIsoBeta_Mu1", 50, 0,1);
  h_Dilep_HWWMu_PFIsoBeta_Mu2 =   CreateH1F("h_Dilep_HWWMu_PFIsoBeta_Mu2", "h_Dilep_HWWMu_PFIsoBeta_Mu2", 50, 0,1);

  h_WWlevel_HWWMu_PFIsoBeta_Mu1 =   CreateH1F("h_WWlevel_HWWMu_PFIsoBeta_Mu1", "h_WWlevel_HWWMu_PFIsoBeta_Mu1", 50, 0,1);
  h_WWlevel_HWWMu_PFIsoBeta_Mu2 =   CreateH1F("h_WWlevel_HWWMu_PFIsoBeta_Mu2", "h_WWlevel_HWWMu_PFIsoBeta_Mu2", 50, 0,1);
   
  //h_Dilep_TightMu_dxyBT_Mu1 =   CreateH1F("h_Dilep_TightMu_dxyBT_Mu1", "h_Dilep_TightMu_dxyBT_Mu1", 100, 0,200);
  //h_Dilep_TightMu_dxyBT_Mu2 =   CreateH1F("h_Dilep_TightMu_dxBT_Mu2", "h_Dilep_TightMu_dxyBT_Mu2", 100, 0,200);
  //h_Dilep_TightMu_dzBT_Mu1 =   CreateH1F("h_Dilep_TightMu_dzBT_Mu1", "h_Dilep_TightMu_dzBT_Mu1", 100, 0,200);
  //h_Dilep_TightMu_dzBT_Mu2 =   CreateH1F("h_Dilep_TightMu_dzBT_Mu2", "h_Dilep_TightMu_dzBT_Mu2", 100, 0,200);


  //------>  Plots after Tight Muon ID at dilepton level

  h_Dilep_TightMuon_TkLayers[0] =  CreateH1F("h_Dilep_TightMuon_TkLayers_Mu1", "h_Dilep_TightMuon_TkLayers_Mu1", 20, 0, 20);
  h_Dilep_TightMuon_TkLayers[1] =  CreateH1F("h_Dilep_TightMuon_TkLayers_Mu2", "h_Dilep_TightMuon_TkLayers_Mu2", 20, 0, 20);

  h_Dilep_TightMuon_StaHits[0] =  CreateH1F("h_Dilep_TightMuon_StaHits_Mu1", "h_Dilep_TightMuon_StaHits_Mu1", 20, 0, 20);
  h_Dilep_TightMuon_StaHits[1] =  CreateH1F("h_Dilep_TightMuon_StaHits_Mu2", "h_Dilep_TightMuon_StaHits_Mu2", 20, 0, 20);

  h_Dilep_TightMu_pt[0]=   CreateH1F("h_Dilep_TightMu_pt_Mu1", "h_Dilep_TightMu_pt_Mu1", 100, 0,200);
  h_Dilep_TightMu_pt[1] =  CreateH1F("h_Dilep_TightMu_pt_Mu2", "h_Dilep_TightMu_pt_Mu2", 100, 0,200);
  h_Dilep_TightMu_eta[0]=   CreateH1F("h_Dilep_TightMu_eta_Mu1", "h_Dilep_TightMu_eta_Mu1", 100, -2.5,2.5);
  h_Dilep_TightMu_eta[1] =  CreateH1F("h_Dilep_TightMu_eta_Mu2", "h_Dilep_TightMu_eta_Mu2", 100, -2.5,2.5);
  h_Dilep_TightMu_PFIsoBeta[0] =   CreateH1F("h_Dilep_TightMu_PFIsoBeta_Mu1", "h_Dilep_TightMu_PFIsoBeta_Mu1", 50, 0,1);
  h_Dilep_TightMu_PFIsoBeta[1] =   CreateH1F("h_Dilep_TihgtMu_PFIsoBeta_Mu2", "h_Dilep_TightMu_PFIsoBeta_Mu2", 50, 0,1); 
 
  h_Dilep_TightMu_PFCH[0] =  CreateH1F("h_Dilep_TightMu_PFCH_Mu1", "h_Dilep_TightMu_PFCH_Mu1",  50, 0,50);
  h_Dilep_TightMu_PFCH[1] = CreateH1F("h_Dilep_TightMu_PFCH_Mu2", "h_Dilep_TightMu_PFCH_Mu2",  50, 0,50);
  h_Dilep_TightMu_PFNH[0] =  CreateH1F("h_Dilep_TightMu_PFNH_Mu1", "h_Dilep_TightMu_PFNH_Mu1", 50, 0,50);
  h_Dilep_TightMu_PFNH[1] = CreateH1F("h_Dilep_TightMu_PFNH_Mu2", "h_Dilep_TightMu_PFNH_Mu2", 50, 0,50);
  h_Dilep_TightMu_PFPh[0] = CreateH1F("h_Dilep_TightMu_PFPh_Mu1", "h_Dilep_TightMu_PFPh_Mu1",  50, 0,50);
  h_Dilep_TightMu_PFPh[1] = CreateH1F("h_Dilep_TightMu_PFPh_Mu2", "h_Dilep_TightMu_PFPh_Mu2",  50, 0,50);
  h_Dilep_TightMu_PFRho[0] = CreateH1F("h_Dilep_TightMu_PFRho_Mu1","h_Dilep_TightMu_PFRho_Mu1", 100,0,100);
  h_Dilep_TightMu_PFRho[1] =  CreateH1F("h_Dilep_TightMu_PFRho_Mu2","h_Dilep_TightMu_PFRho_Mu2", 100,0,100);


  h_Dilep_TightMu_RelEff[0] = CreateH1F("h_Dilep_TightMu_RelEff_Mu1", "h_Dilep_TightMu_RelEff_Mu1", 8, 1,9);
  h_Dilep_TightMu_RelEff[1] = CreateH1F("h_Dilep_TightMu_RelEff_Mu2", "h_Dilep_TightMu_RelEff_Mu2", 8, 1,9);

  h_Dilep_Chi2[0] = CreateH1F("h_Dilep_Chi2_Mu1", "h_Dilep_Chi2_Mu1", 100, 0, 20);
  h_Dilep_Chi2[1] = CreateH1F("h_Dilep_Chi2_Mu2", "h_Dilep_Chi2_Mu2", 100, 0, 20);
  h_Dilep_StaHits[0] = CreateH1F("h_Dilep_StaHits_Mu1", "h_Dilep_StaHits_Mu1", 50, 0, 50);
  h_Dilep_StaHits[1] = CreateH1F("h_Dilep_StaHits_Mu2", "h_Dilep_StaHits_Mu2", 50, 0, 50);
  h_Dilep_StaNStation[0] = CreateH1F("h_Dilep_StaNStation_Mu1", "h_Dilep_StaNStation_Mu1", 5, -0.5, 4.5);
  h_Dilep_StaNStation[1] = CreateH1F("h_Dilep_StaNStation_Mu2", "h_Dilep_StaNStation_Mu2", 5, -0.5, 4.5);
  h_Dilep_PixelHits[0] = CreateH1F("h_Dilep_PixelHits_Mu1","h_Dilep_PixelHits_Mu1", 6, -0.5, 5.5);
  h_Dilep_PixelHits[1] = CreateH1F("h_Dilep_PixelHits_Mu2","h_Dilep_PixelHits_Mu2", 6, -0.5, 5.5);

  //h_Dilep_TkLayersCuts[1] = CreateH1F("h_Dilep_TkLayersCuts_Mu2", "h_Dilep_TkLayersCuts_Mu2", 20, 0, 20);  
  //h_Dilep_TkLayersCuts[2] = CreateH1F("h_Dilep_TkLayersCuts_Mu2", "h_Dilep_TkLayersCuts_Mu2", 20, 0, 20);  

  h_Dilep_TkLayers[0] = CreateH1F("h_Dilep_TkLayers_Mu1", "h_Dilep_TkLayers_Mu1", 20, 0, 20);
  h_Dilep_TkLayers[1] = CreateH1F("h_Dilep_TkLayers_Mu2", "h_Dilep_TkLayers_Mu2", 20, 0, 20);
  
  h_Dilep_StaHitsEta[0] = CreateH2F("h_Dilep_StaHitsEta_Mu1", "h_Dilep_StaHitsEta_Mu1", 50,-2.5,2.5, 50, 0, 50);
  h_Dilep_StaHitsEta[1] = CreateH2F("h_Dilep_StaHitsEta_Mu2", "h_Dilep_StaHitsEta_Mu2", 50,-2.5,2.5, 50, 0, 50);
  h_Dilep_StaHitsPV[0] = CreateH2F("h_Dilep_StaHitsPV_Mu1", "h_Dilep_StaHitsPV_Mu1", 50,0,50, 50, 0, 50);
  h_Dilep_StaHitsPV[1] = CreateH2F("h_Dilep_StaHitsPV_Mu2", "h_Dilep_StaHitsPV_Mu2", 50,0,50, 50, 0, 50);
 
  h_Dilep_StaNStationEta[0] = CreateH2F("h_Dilep_StaNStationEta_Mu1", "h_Dilep_StaNStationEta_Mu1",50,-2.5,2.5, 5, -0.5, 4.5);
  h_Dilep_StaNStationEta[1] = CreateH2F("h_Dilep_StaNStationEta_Mu2", "h_Dilep_StaNStationEta_Mu2", 50,-2.5,2.5, 5, -0.5, 4.5);
  h_Dilep_StaNStationPV[0] = CreateH2F("h_Dilep_StaNStationPV_Mu1", "h_Dilep_StaNStationPV_Mu1", 50,0,50,5, -0.5, 4.5);
  h_Dilep_StaNStationPV[1] = CreateH2F("h_Dilep_StaNStationPV_Mu2", "h_Dilep_StaNStationPV_Mu2", 50,0,50,5, -0.5, 4.5);

  h_Dilep_dxy[0] = CreateH1F("h_Dilep_dxy_Mu1", "h_Dilep_dxy_Mu1", 100, 0.0, 0.2);
  h_Dilep_dxy[1] = CreateH1F("h_Dilep_dxy_Mu2", "h_Dilep_dxy_Mu2", 100, 0.0, 0.2);

  h_Dilep_dz_GTrack[0] = CreateH1F("h_Dilep_dz_GTrack_Mu1", "h_Dilep_dz_GTrack_Mu1", 100, 0.0, 4.0);
  h_Dilep_dz_GTrack[1] = CreateH1F("h_Dilep_dz_GTrack_Mu2", "h_Dilep_dz_GTrack_Mu2", 100, 0.0, 4.0);
  h_Dilep_dz_InTrack[0] = CreateH1F("h_Dilep_dz_InTrack_Mu1", "h_Dilep_dz_InTrack_Mu1", 100, 0.0, 0.5);
  h_Dilep_dz_InTrack[1] = CreateH1F("h_Dilep_dz_InTrack_Mu2", "h_Dilep_dz_InTrack_Mu2", 100, 0.0, 0.5);

  //dz Plots at Dileptonic level after GLB and PF Muon. Independent muons
  //Key:
  //  dz           = Standard PV Selection, Vertex_z method
  //  dzMu         = New PV Selection, Vertex_z method
  //  dz_BestTrack = Standard PV Selection, dzBestTrack method

  h_Dilep_dz[0] = CreateH1F("h_Dilep_dz_Mu1", "h_Dilep_dz_Mu1", 100, 0.0, 0.5);
  h_Dilep_dz[1] = CreateH1F("h_Dilep_dz_Mu2", "h_Dilep_dz_Mu2", 100, 0.0, 0.5);
  h_Dilep_dzMu[0] = CreateH1F("h_Dilep_dzMu_Mu1", "h_Dilep_dzMu_Mu1", 100, 0.0, 0.5);
  h_Dilep_dzMu[1] = CreateH1F("h_Dilep_dzMu_Mu2", "h_Dilep_dzMu_Mu2", 100, 0.0, 0.5);
  h_Dilep_dz_BestTrack[0] = CreateH1F("h_Dilep_dz_BestTrack_Mu1", "h_Dilep_dz_BestTrack_Mu1", 100, 0.0, 0.5);
  h_Dilep_dz_BestTrack[1] = CreateH1F("h_Dilep_dz_BestTrack_Mu2", "h_Dilep_dz_BestTrack_Mu2", 100, 0.0, 0.5);

  //dz Plots at  Dileptonic level after TightID selection before d_xy cut. Independent muons

  h_Dilep_dz_bf_dy[0] = CreateH1F("h_Dilep_dz_bf_dy_Mu1", "h_Dilep_dz_bf_dy_Mu1", 100, 0.0, 4.0);
  h_Dilep_dz_bf_dy[1] = CreateH1F("h_Dilep_dz_bf_dy_Mu2", "h_Dilep_dz_bf_dy_Mu2", 100, 0.0, 4.0);
  h_Dilep_dzMu_bf_dy[0] = CreateH1F("h_Dilep_dzMu_bf_dy_Mu1", "h_Dilep_dzMu_bf_dy_Mu1", 100, 0.0, 4.0);
  h_Dilep_dzMu_bf_dy[1] = CreateH1F("h_Dilep_dzMu_bf_dy_Mu2", "h_Dilep_dzMu_bf_dy_Mu2", 100, 0.0, 4.0);
  h_Dilep_dz_BestTrack_bf_dy[0] = CreateH1F("h_Dilep_dz_BestTrack_bf_dy_Mu1", "h_Dilep_dz_BestTrack_bf_dy_Mu1", 100, 0.0, 4.0);
  h_Dilep_dz_BestTrack_bf_dy[1] = CreateH1F("h_Dilep_dz_BestTrack_bf_dy_Mu2", "h_Dilep_dz_BestTrack_bf_dy_Mu2", 100, 0.0, 4.0);

  //dz Plots at Dileptonic level after GLB and PF Muon. Selecting both muons at the same time.

  h_TrueDilep_dz[0] = CreateH1F("h_TrueDilep_dz_Mu1", "h_TrueDilep_dz_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dz[1] = CreateH1F("h_TrueDilep_dz_Mu2", "h_TrueDilep_dz_Mu2", 100, 0.0, 0.5);
  h_TrueDilep_dzMu[0] = CreateH1F("h_TrueDilep_dzMu_Mu1", "h_TrueDilep_dzMu_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dzMu[1] = CreateH1F("h_TrueDilep_dzMu_Mu2", "h_TrueDilep_dzMu_Mu2", 100, 0.0, 0.5);
  h_TrueDilep_dz_BestTrack[0] = CreateH1F("h_TrueDilep_dz_BestTrack_Mu1", "h_TrueDilep_dz_BestTrack_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dz_BestTrack[1] = CreateH1F("h_TrueDilep_dz_BestTrack_Mu2", "h_TrueDilep_dz_BestTrack_Mu2", 100, 0.0, 0.5);

  //dz Plots at  Dileptonic level after TightID selection before d_xy cut. Selecting both muons at the same time.

  h_TrueDilep_dz_bf_dy[0] = CreateH1F("h_TrueDilep_dz_bf_dy_Mu1", "h_TrueDilep_dz_bf_dy_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dz_bf_dy[1] = CreateH1F("h_TrueDilep_dz_bf_dy_Mu2", "h_TrueDilep_dz_bf_dy_Mu2", 100, 0.0, 0.5);
  h_TrueDilep_dzMu_bf_dy[0] = CreateH1F("h_TrueDilep_dzMu_bf_dy_Mu1", "h_TrueDilep_dzMu_bf_dy_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dzMu_bf_dy[1] = CreateH1F("h_TrueDilep_dzMu_bf_dy_Mu2", "h_TrueDilep_dzMu_bf_dy_Mu2", 100, 0.0, 0.5);
  h_TrueDilep_dz_BestTrack_bf_dy[0] = CreateH1F("h_TrueDilep_dz_BestTrack_bf_dy_Mu1", "h_TrueDilep_dz_BestTrack_bf_dy_Mu1", 100, 0.0, 0.5);
  h_TrueDilep_dz_BestTrack_bf_dy[1] = CreateH1F("h_TrueDilep_dz_BestTrack_bf_dy_Mu2", "h_TrueDilep_dz_BestTrack_bf_dy_Mu2", 100, 0.0, 0.5);

  //dz Plots at Dileptonic level after GLB and PF Muon. Independent muons.
  //Key:
  // PVSel_Equal:     The PV selected by the two criteria is the same
  // PVSel_Not_Equal: The PV selected by the two criteria is not the same

  h_Dilep_dz_PV_Eq[0] = CreateH1F("h_Dilep_dz_PVSel_Equal_Mu1", "h_Dilep_dz_PVSel_Equal_Mu1", 100, 0.0, 0.5);
  h_Dilep_dz_PV_Eq[1] = CreateH1F("h_Dilep_dz_PVSel_Equal_Mu2", "h_Dilep_dz_PVSel_Equal_Mu2", 100, 0.0, 0.5);
  h_Dilep_dzMu_PV_Eq[0] = CreateH1F("h_Dilep_dzMu_PVSel_Equal_Mu1", "h_Dilep_dzMu_PVSel_Equal_Mu1", 100, 0.0, 0.5);
  h_Dilep_dzMu_PV_Eq[1] = CreateH1F("h_Dilep_dzMu_PVSel_Equal_Mu2", "h_Dilep_dzMu_PVSel_Equal_Mu2", 100, 0.0, 0.5);

  h_Dilep_dz_PV_NEq[0] = CreateH1F("h_Dilep_dz_PVSel_Not_Equal_Mu1", "h_Dilep_dz_PVSel_Not_Equal_Mu1", 100, 0.0, 0.5);
  h_Dilep_dz_PV_NEq[1] = CreateH1F("h_Dilep_dz_PVSel_Not_Equal_Mu2", "h_Dilep_dz_PVSel_Not_Equal_Mu2", 100, 0.0, 0.5);
  h_Dilep_dzMu_PV_NEq[0] = CreateH1F("h_Dilep_dzMu_PVSel_Not_Equal_Mu1", "h_Dilep_dzMu_PVSel_Not_Equal_Mu1", 100, 0.0, 0.5);
  h_Dilep_dzMu_PV_NEq[1] = CreateH1F("h_Dilep_dzMu_PVSel_Not_Equal_Mu2", "h_Dilep_dzMu_PVSel_Not_Equal_Mu2", 100, 0.0, 0.5);

  //Plots for dileptonic signal Efficiency at Dileptonic level and GLB and PF Muon after appying dz cut on both muons: dz1 < 0.1, dz2 < 0.01 from 0.10 in 0.01 steps

  h_2D_Dilep_dz_Eff = CreateH1F("h_2D_Dilep_dz_Eff","h_2D_Dilep_dz_Eff",10,0,10);
  h_2D_Dilep_dzMu_Eff = CreateH1F("h_2D_Dilep_dzMu_Eff","h_2D_Dilep_dzMu_Eff",10,0,10);
  h_2D_Dilep_dzBT_Eff = CreateH1F("h_2D_Dilep_dzBestTrack_Eff","h_2D_Dilep_dzBestTrack_Eff",10,0,10);

  //Plots for dileptonic signal Efficiency at Dileptonic level and TightID selection before d_xy cut after appying dz cut on both muons: dz1 < 0.1, dz2 < 0.01 from 0.10 in 0.01 steps

  h_2D_Dilep_dz_bf_dy_Eff = CreateH1F("h_2D_Dilep_dz_bf_dy_Eff","h_2D_Dilep_dz_bf_dy_Eff",10,0,10);
  h_2D_Dilep_dzMu_bf_dy_Eff = CreateH1F("h_2D_Dilep_dzMu_bf_dy_Eff","h_2D_Dilep_dzMu_bf_dy_Eff",10,0,10);
  h_2D_Dilep_dzBT_bf_dy_Eff = CreateH1F("h_2D_Dilep_dzBestTrack_bf_dy_Eff","h_2D_Dilep_dzBestTrack_bf_dy_Eff",10,0,10);

  //dz 2D Plots at Dileptonic level after GLB and PF Muon. Selecting both muons at the same time.

  h_2D_Dilep_dz = CreateH2F("h_2D_Dilep_dz","h_2D_Dilep_dz",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu = CreateH2F("h_2D_Dilep_dzMu","h_2D_Dilep_dzMu",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT = CreateH2F("h_2D_Dilep_dzBestTrack","h_2D_Dilep_dzBestTrack",50,0.0,0.5,50,0.0,0.5);

  h_2D_Dilep_dz_PV_Eq = CreateH2F("h_2D_Dilep_dz_PVSel_Equal","h_2D_Dilep_dz_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu_PV_Eq = CreateH2F("h_2D_Dilep_dzMu_PVSel_Equal","h_2D_Dilep_dzMu_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT_PV_Eq = CreateH2F("h_2D_Dilep_dzBestTrack_PVSel_Equal","h_2D_Dilep_dzBestTrack_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);

  h_2D_Dilep_dz_PV_NEq = CreateH2F("h_2D_Dilep_dz_PVSel_Not_Equal","h_2D_Dilep_dz_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu_PV_NEq = CreateH2F("h_2D_Dilep_dzMu_PVSel_Not_Equal","h_2D_Dilep_dzMu_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT_PV_NEq = CreateH2F("h_2D_Dilep_dzBestTrack_PVSel_Not_Equal","h_2D_Dilep_dzBestTrack_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);

  h_2D_Dilep_dz_bf_dy = CreateH2F("h_2D_Dilep_dz_bf_dy","h_2D_Dilep_dz_bf_dy",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu_bf_dy = CreateH2F("h_2D_Dilep_dzMu_bf_dy","h_2D_Dilep_dzMu_bf_dy",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT_bf_dy = CreateH2F("h_2D_Dilep_dzBestTrack_bf_dy","h_2D_Dilep_dzBestTrack_bf_dy",50,0.0,0.5,50,0.0,0.5);

  //dz 2D Plots at Dileptonic level after TightID selection before d_xy cut. Selecting both muons at the same time.

  h_2D_Dilep_dz_bf_dy_PV_Eq = CreateH2F("h_2D_Dilep_dz_bf_dy_PVSel_Equal","h_2D_Dilep_dz_bf_dy_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu_bf_dy_PV_Eq = CreateH2F("h_2D_Dilep_dzMu_bf_dy_PVSel_Equal","h_2D_Dilep_dzMu_bf_dy_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT_bf_dy_PV_Eq = CreateH2F("h_2D_Dilep_dzBestTrack_bf_dy_PVSel_Equal","h_2D_Dilep_bf_dy_dzBestTrack_PVSel_Equal",50,0.0,0.5,50,0.0,0.5);

  h_2D_Dilep_dz_bf_dy_PV_NEq = CreateH2F("h_2D_Dilep_dz_bf_dy_PVSel_Not_Equal","h_2D_Dilep_dz_bf_dy_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzMu_bf_dy_PV_NEq = CreateH2F("h_2D_Dilep_dzMu_bf_dy_PVSel_Not_Equal","h_2D_Dilep_dzMu_bf_dy_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);
  h_2D_Dilep_dzBT_bf_dy_PV_NEq = CreateH2F("h_2D_Dilep_dzBestTrack_bf_dy_PVSel_Not_Equal","h_2D_Dilep_dzBestTrack_bf_dy_PVSel_Not_Equal",50,0.0,0.5,50,0.0,0.5);

  h_Dilep_Jet_Energy = CreateH1F("h_Dilep_Jet_Energy", "h_Dilep_Jet_Energy", 100, 0.0, 200);
  h_Dilep_Jet_Energy_PV_Eq = CreateH1F("h_Dilep_Jet_Energy_PVSel_Equal", "h_Dilep_Jet_Energy_PVSel_Equal", 100, 0.0, 200);
  h_Dilep_Jet_Energy_PV_NEq = CreateH1F("h_Dilep_Jet_Energy_PVSel_Not_Equal", "h_Dilep_Jet_Energy_PVSel_Not_Equal", 100, 0.0, 200);

  h_Dilep_N_Jets = CreateH1F("h_Dilep_N_Jets", "h_Dilep_N_Jets", 10, 0, 10); 
  h_Dilep_N_Jets_PV_Eq = CreateH1F("h_Dilep_N_Jets_PVSel_Equal", "h_Dilep_N_Jets_PVSel_Equal", 10, 0, 10);
  h_Dilep_N_Jets_PV_NEq = CreateH1F("h_Dilep_N_Jets_PVSel_Not_Equal", "h_Dilep_N_Jets_PVSel_Not_Equal", 10, 0, 10);

  // pdg ID of Mother particle for non prompt muons

  h_Dilep_Gen_Muon_MpdgId = CreateH1F("h_Dilep_Gen_Muon_MpdgId","h_Dilep_Gen_Muon_MpdgId", 12000, -6000, 6000);
  h_Dilep_Gen_Muon_MpdgId_PV_Eq = CreateH1F("h_Dilep_Gen_Muon_MpdgId_PVSel_Equal","h_Dilep_Gen_Muon_MpdgId_PVSel_Equal", 12000, -6000, 6000); 
  h_Dilep_Gen_Muon_MpdgId_PV_NEq = CreateH1F("h_Dilep_Gen_Muon_MpdgId_PVSel_Not_Equal","h_Dilep_Gen_Muon_MpdgId_PVSel_Not_Equal", 12000, -6000, 6000);


  //------>  Plots after Tight Muon ID+ISO at dilepton level
  h_Dilep_TightMuISO_pt[0]=   CreateH1F("h_Dilep_TightMuISO_pt_Mu1", "h_Dilep_TightMuISO_pt_Mu1", 100, 0,200);
  h_Dilep_TightMuISO_pt[1] =  CreateH1F("h_Dilep_TightMuISO_pt_Mu2", "h_Dilep_TightMuISO_pt_Mu2", 100, 0,200);
  h_Dilep_TightMuISO_eta[0]=   CreateH1F("h_Dilep_TightMuISO_eta_Mu1", "h_Dilep_TightMuISO_eta_Mu1", 100, -2.5,2.5);
  h_Dilep_TightMuISO_eta[1] =  CreateH1F("h_Dilep_TightMuISO_eta_Mu2", "h_Dilep_TightMuISO_eta_Mu2", 100, -2.5,2.5);

 //------>  Plots after Tight Muon ID at WW level 
  h_WWlevel_TightMu_pt[0] =   CreateH1F("h_WWlevel_TightMu_pt_Mu1", "h_WWlevel_TightMu_pt_Mu1", 100, 0,200);
  h_WWlevel_TightMu_pt[1] =   CreateH1F("h_WWlevel_TightMu_pt_Mu2", "h_WWlevel_TightMu_pt_Mu2", 100, 0,200);
  h_WWlevel_TightMu_eta[0]=   CreateH1F("h_WWlevel_TightMu_eta_Mu1", "h_WWlevel_TightMu_eta_Mu1", 100, -2.5,2.5);
  h_WWlevel_TightMu_eta[1] =  CreateH1F("h_WWlevel_TightMu_eta_Mu2", "h_WWlevel_TightMu_eta_Mu2", 100, -2.5,2.5);
  h_WWlevel_TightMu_PFIsoBeta[0] =   CreateH1F("h_WWlevel_TightMu_PFIsoBeta_Mu1", "h_WWlevel_TightMu_PFIsoBeta_Mu1", 50, 0,1);
  h_WWlevel_TightMu_PFIsoBeta[1] =   CreateH1F("h_WWlevel_TightMu_PFIsoBeta_Mu2", "h_WWlevel_TightMu_PFIsoBeta_Mu2", 50, 0,1);

  h_WWlevel_Chi2[0] = CreateH1F("h_WWlevel_Chi2_Mu1", "h_WWlevel_Chi2_Mu1", 100, 0, 20);
  h_WWlevel_Chi2[1] = CreateH1F("h_WWlevel_Chi2_Mu2", "h_WWlevel_Chi2_Mu2", 100, 0, 20);
  h_WWlevel_StaHits[0] = CreateH1F("h_WWlevel_StaHits_Mu1", "h_WWlevel_StaHits_Mu1", 50, 0, 50);
  h_WWlevel_StaHits[1] = CreateH1F("h_WWlevel_StaHits_Mu2", "h_WWlevel_StaHits_Mu2", 50, 0, 50);

  h_WWlevel_StaNStation[0] = CreateH1F("h_WWlevel_StaNStation_Mu1", "h_WWlevel_StaNStation_Mu1", 5, -0.5, 4.5);
  h_WWlevel_StaNStation[1] = CreateH1F("h_WWlevel_StaNStation_Mu2", "h_WWlevel_StaNStation_Mu2", 5, -0.5, 4.5);

  h_WWlevel_PixelHits[0] = CreateH1F("h_WWlevel_PixelHits_Mu1","h_WWlevel_PixelHits_Mu1", 6, -0.5, 5.5);
  h_WWlevel_PixelHits[1] = CreateH1F("h_WWlevel_PixelHits_Mu2","h_WWlevel_PixelHits_Mu2", 6, -0.5, 5.5);
  h_WWlevel_TkLayers[0] = CreateH1F("h_WWlevel_TkLayers_Mu1", "h_WWlevel_TkLayers_Mu1", 20, 0, 20);
  h_WWlevel_TkLayers[1] = CreateH1F("h_WWlevel_TkLayers_Mu2", "h_WWlevel_TkLayers_Mu2", 20, 0, 20);
  h_WWlevel_dxy[0] = CreateH1F("h_WWlevel_dxy_Mu1", "h_WWlevel_dxy_Mu1", 100, -0.4, 0.4);
  h_WWlevel_dxy[1] = CreateH1F("h_WWlevel_dxy_Mu2", "h_WWlevel_dxy_Mu2", 100, -0.4, 0.4);
  h_WWlevel_dz[0] = CreateH1F("h_WWlevel_dz_Mu1", "h_WWlevel_dz_Mu1", 100, -1.0, 1.0);
  h_WWlevel_dz[1] = CreateH1F("h_WWlevel_dz_Mu2", "h_WWlevel_dz_Mu2", 100, -1.0, 1.0);

  //------>  Plots after Tight Muon ID+ISO at WW level
  h_WWlevel_TightMuISO_pt[0]=   CreateH1F("h_WWlevel_TightMuISO_pt_Mu1", "h_WWlevel_TightMuISO_pt_Mu1", 100, 0,200);
  h_WWlevel_TightMuISO_pt[1] =  CreateH1F("h_WWlevel_TightMuISO_pt_Mu2", "h_WWlevel_TightMuISO_pt_Mu2", 100, 0,200);
  h_WWlevel_TightMuISO_eta[0]=   CreateH1F("h_WWlevel_TightMuISO_eta_Mu1", "h_WWlevel_TightMuISO_eta_Mu1", 100, -2.5,2.5);
  h_WWlevel_TightMuISO_eta[1] =  CreateH1F("h_WWlevel_TightMuISO_eta_Mu2", "h_WWlevel_TightMuISO_eta_Mu2", 100, -2.5,2.5);


}



void muonAnalyzer::InsideLoop() {
 



 // The InsideLoop() function is called for each entry in the tree to be processed  

  // Define Normalization Factor for MC samples 



//------------------------------------------------------------------------------
// Define weights
//------------------------------------------------------------------------------
 
  float pileupweight = 1;

  //  if (!IsDATA)
    // pileupweight = fPUWeight->GetWeight(T_Event_nPU);




  double factN = 1;
  
  if (XSection > 0) factN = XSection * Luminosity / NEvents;


  //factN = factN*pileupweight;


  //------------------------------------------------------------------------------
  // Init variables
  //------------------------------------------------------------------------------

  ///** GEN INFORMATION
  G_GEN_PromptMuon_4vec.clear();
  G_GEN_Muon_4vec.clear();
  G_GEN_PromptTauMuon_4vec.clear();

  ///** MUONS
  G_Muon_4vec.clear();
  G_Muon_HWW_ID.clear();
  G_Muon_HWW_ISO.clear();
  G_Muon_TightID.clear();
  G_Muon_TightISO.clear();
  G_Muon_PFIsoBeta.clear();
  G_Muon_PFChargedH.clear();
  G_Muon_PFNeutralH.clear();
  G_Muon_PFPhoton.clear();
  G_Muon_PFRho.clear();
  G_Muon_MatchW.clear();

  ///** JETS 
  G_Jet_4vec.clear();
  G_N_Jets = -999;

 

  

//------------------------------------------------------------------------------
// Get all muons
//------------------------------------------------------------------------------


  UInt_t muonSize = 0;

  muonSize = T_Muon_Px->size();
  
  
  if ( muonSize > 0 ) {  // asking for at least one muon in the event 
    
    if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get Tight Muons " << std::endl;

    for (unsigned int i = 0; i < muonSize; i++) {
      
      //-->define the global 4D momentum for each muon. 
      G_Muon_4vec.push_back(TLorentzVector(T_Muon_Px->at(i), T_Muon_Py->at(i),T_Muon_Pz->at(i), T_Muon_Energy->at(i)));

    }
  }
 
  GetAllHWWMuons();

  GetAllTightMuons();
 

//------------------------------------------------------------------------------
// Get all GEN prompt muon for CSA14 samples 
//------------------------------------------------------------------------------

  bool isMuMu  = false; 
  bool isTauTau = false; 
  bool isTauMu = false;
  bool isNonPrompt = false;
  
  
  

  if ( Signal=="MC_Wjets_S14" || Signal=="MC_Wjets_PU20bx25" ) {
    
    UInt_t genPromptMuSize = 0;
    genPromptMuSize = T_Gen_PromptMuon_Px->size();
    
    UInt_t genNonPromptMuSize = 0;
    genNonPromptMuSize = T_Gen_Muon_Px->size();
  
    UInt_t genPromptTauSize = 0;
    genPromptTauSize = T_Gen_PromptTau_Px->size(); 
    
    if ( genPromptMuSize == 1 && fabs(T_Gen_PromptMuon_MpdgId->at(0)) == 24) isMuMu = true; 
    
    if ( genPromptMuSize < 1 && genPromptTauSize == 1 && fabs(T_Gen_PromptTau_MpdgId->at(0))== 24 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(0)) == 13) isTauMu = true; 
    
    if ( isMuMu ) {
      G_GEN_PromptMuon_4vec.push_back(TLorentzVector(T_Gen_PromptMuon_Px->at(0), T_Gen_PromptMuon_Py->at(0),T_Gen_PromptMuon_Pz->at(0), T_Gen_PromptMuon_Energy->at(0)));
      if ( genNonPromptMuSize > 0) {
	isNonPrompt = true;
	G_GEN_Muon_4vec.push_back(TLorentzVector(T_Gen_Muon_Px->at(0), T_Gen_Muon_Py->at(0),T_Gen_Muon_Pz->at(0), T_Gen_Muon_Energy->at(0)));
      }
    } 
    
    if ( isTauMu ) {
      G_GEN_PromptTauMuon_4vec.push_back(TLorentzVector(T_Gen_PromptTau_LepDec_Px->at(0),T_Gen_PromptTau_LepDec_Py->at(0),T_Gen_PromptTau_LepDec_Pz->at(0), T_Gen_PromptTau_LepDec_Energy->at(0)));
      if ( genNonPromptMuSize > 1) {
	isNonPrompt = true;
	G_GEN_Muon_4vec.push_back(TLorentzVector(T_Gen_Muon_Px->at(1), T_Gen_Muon_Py->at(1),T_Gen_Muon_Pz->at(1), T_Gen_Muon_Energy->at(1)));
      }
    }
     
  }
  
  
  if (Signal=="MC_GGHWW_S14" || Signal=="MC_GGHWW_PU20bx25" ) { 

    UInt_t genPromptMuSize = 0;
    genPromptMuSize = T_Gen_PromptMuon_Px->size();
  
    UInt_t genPromptTauSize = 0;
    genPromptTauSize = T_Gen_PromptTau_Px->size(); 

    if ( genPromptMuSize == 2 && fabs(T_Gen_PromptMuon_MpdgId->at(0)) == 24 && fabs(T_Gen_PromptMuon_MpdgId->at(1)) == 24 ) isMuMu = true; 
  
    if ( genPromptMuSize == 1 && fabs(T_Gen_PromptMuon_MpdgId->at(0)) == 24 && genPromptTauSize == 1 && fabs(T_Gen_PromptTau_MpdgId->at(0))== 24 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(0)) == 13 ) isTauMu = true;
 
    if ( genPromptMuSize < 1 && genPromptTauSize == 2 && fabs(T_Gen_PromptTau_MpdgId->at(0))== 24 && fabs(T_Gen_PromptTau_MpdgId->at(1))== 24 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(0)) == 13 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(1)) == 13) isTauTau = true; 

    //  cout << genPromptMuSize  << "  " << genPromptTauSize << "  " << isTauTau << endl;
    
    
    if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get Tight Muons " << std::endl;
    
    for (unsigned int i = 0; i < genPromptMuSize; i++) {
      
      //-->define the global 4D momentum for each muon. 
      G_GEN_PromptMuon_4vec.push_back(TLorentzVector(T_Gen_FinalMuon_Px->at(i), T_Gen_FinalMuon_Py->at(i),T_Gen_FinalMuon_Pz->at(i), T_Gen_FinalMuon_Energy->at(i)));
    
    }
   
  }

  if (Signal=="MC_DY_S14" || Signal=="MC_DY_PU20bx25" ) { 

    UInt_t genPromptMuSize = 0;
    genPromptMuSize = T_Gen_PromptMuon_Px->size();
  
    UInt_t genPromptTauSize = 0;
    genPromptTauSize = T_Gen_PromptTau_Px->size(); 

    if ( genPromptMuSize == 2 && fabs(T_Gen_PromptMuon_MpdgId->at(0)) == 23 && fabs(T_Gen_PromptMuon_MpdgId->at(1)) == 23 ) isMuMu = true; 
  
    if ( genPromptMuSize == 1 && fabs(T_Gen_PromptMuon_MpdgId->at(0)) == 23 && genPromptTauSize == 1 && fabs(T_Gen_PromptTau_MpdgId->at(0))== 23 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(0)) == 13 ) isTauMu = true;
 
    if ( genPromptMuSize < 1 && genPromptTauSize == 2 && fabs(T_Gen_PromptTau_MpdgId->at(0))== 23 && fabs(T_Gen_PromptTau_MpdgId->at(1))== 23 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(0)) == 13 && fabs(T_Gen_PromptTau_LepDec_pdgId->at(1)) == 13) isTauTau = true; 

    //  cout << genPromptMuSize  << "  " << genPromptTauSize << "  " << isTauTau << endl;
    
    
    //if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get Tight Muons " << std::endl;
    
    //for (unsigned int i = 0; i < genPromptMuSize; i++) {
      
      //-->define the global 4D momentum for each muon. 
      //G_GEN_PromptMuon_4vec.push_back(TLorentzVector(T_Gen_FinalMuon_Px->at(0), T_Gen_FinalMuon_Py->at(0),T_Gen_FinalMuon_Pz->at(0), T_Gen_FinalMuon_Energy->at(0)));
    
  }
   
  
  
    
  
  /*
   
  
    if (Signal=="MC_Wjets_8TeV") {
    
    UInt_t genMuSize = 0;
    genMuSize = T_Gen_Muon_Px->size();
    
    if ( genMuSize == 1 && fabs(T_Gen_Muon_MPID->at(0)) == 24) {
    
    isMuMu = true; 
    
    G_GEN_PromptMuon_4vec.push_back(TLorentzVector(T_Gen_Muon_Px->at(0), T_Gen_Muon_Py->at(0),T_Gen_Muon_Pz->at(0), T_Gen_Muon_Energy->at(0))); 
    
    }
    
    //      cout << genMuSize << "  " << T_Gen_Muon_MPID->at(0) << "  " <<  T_Gen_Muon_MPID->at(1) << endl;
    }
    
  */
  


//------------------------------------------------------------------------------
// Get all jets
//------------------------------------------------------------------------------

  // unsigned int NjetsCollection=0;
  // double Missing_ET = 0;
  // double Missing_ET_Phi = 0;

  
  // NjetsCollection = T_JetAKCHS_Px->size();  
  // Missing_ET = T_METPF_ET; 
  // Missing_ET_Phi = T_METPF_Phi;
 

  //GetAllJets();



//------------------------------------------------------------------------------
// Get number of good vertex per event
//------------------------------------------------------------------------------

  Int_t N_PV = 0;
  N_PV = T_Vertex_z->size();
  h_N_PV->Fill(N_PV, factN);
  
  
//--------------------------------------------------------------------------------
// PRE-SELECTION:: Dilepton selection
//--------------------------------------------------------------------------------
  
  // Select the first two muons with higher pt (i==0 and i==1) 
  
  if ( T_Muon_Px->size() > 1 ) {  // require events with at least two muons 
    
    if ( G_Muon_4vec[0].Perp() > 20 &&  fabs(G_Muon_4vec[0].Eta()) < 2.4 && G_Muon_4vec[1].Perp() > 10 && fabs(G_Muon_4vec[1].Eta()) < 2.4 ) { 
 
      int ch1 = T_Muon_Charge->at(0);
      int ch2 = T_Muon_Charge->at(1);

      if ( ch1*ch2 < 0 ) {
	
	h_Dilep_AllMu_PFIsoBeta_Mu1->Fill(G_Muon_PFIsoBeta[0], factN);
	h_Dilep_AllMu_PFIsoBeta_Mu2->Fill(G_Muon_PFIsoBeta[1], factN);
	
	 if(T_Muon_isPFMuon->at(0) && T_Muon_IsGlobalMuon->at(0) &&
	    T_Muon_isPFMuon->at(1) && T_Muon_IsGlobalMuon->at(1)) {
	   
	   h_N_Dilep_TypeMu->Fill(0.0, factN);
	   h_N_Dilep_TigtMuCuts->Fill(0.0,  factN);

	 }

	if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_Dilep_TypeMu_LP->Fill(0.0, factN);
	if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_Dilep_TypeMu_HP->Fill(0.0, factN);


	//------>  Plot for relative efficiency of each Tight muon cut, for Mu1 and Mu2
	//------>  Match to a GEN Prompt Muons

	int Mu1 = 0; 
	int Mu2 = 1;

	int iVertex = -999;
	int newiVertex = -999;

	double dZVertex = 999.0;


       if (Signal=="MC_GGHWW_S14" || Signal=="MC_GGHWW_PU20bx25" || Signal=="MC_DY_S14" || Signal=="MC_DY_PU20bx25") {    

	 Mu1 = 0;	 Mu2 = 1;  
	 
	 if ( isMuMu || isTauMu || isTauTau) {   // Matched to a WW or Z gen event 
	 
	   /*if ( passTightMuCuts(Mu1,0.01,0.02,0.1,0,0) ) {  
	     h_Dilep_TightMuon_TkLayers[0]->Fill(T_Muon_NLayers->at(Mu1), factN);
	     h_Dilep_TightMuon_StaHits[0]->Fill(T_Muon_NValidHitsSATrk->at(Mu1), factN);
	   }

	   if ( passTightMuCuts(Mu2,0.01,0.02,0.1,0,0) ) { 
	     h_Dilep_TightMuon_TkLayers[1]->Fill(T_Muon_NLayers->at(Mu2), factN);
	     h_Dilep_TightMuon_StaHits[1]->Fill(T_Muon_NValidHitsSATrk->at(Mu2), factN);
	     }*/

	   iVertex    = SelectedVertexIndex();
	   newiVertex = SelectedVertexIndex(Mu1, factN); //--> Select the closest vertex to Mu1

	   h_N_PV0_PVLep->Fill(newiVertex - iVertex);

	   dZVertex = T_Vertex_z->at(iVertex) - T_Vertex_z->at(newiVertex);
	   h_N_dZ_PV0_PVLep->Fill(dZVertex);

	   FillRelEff("Dilep", 0, Mu1, factN, iVertex, newiVertex);
	   FillRelEff("Dilep", 1, Mu2, factN, iVertex, newiVertex);

	   Filldz2D(Mu1, Mu2, factN, iVertex, newiVertex);
	 }
       }

       else if (Signal=="MC_GGHWW_8TeV" || Signal=="MC_DY_8TeV") { 

	 isMuMu = true;

	 Mu1 = 0;	 Mu2 = 1;  

	 /*if ( passTightMuCuts(Mu1,0.01,0.02,0.1,0,0) ) {  
	   h_Dilep_TightMuon_TkLayers[0]->Fill(T_Muon_NLayers->at(Mu1), factN);
	   h_Dilep_TightMuon_StaHits[0]->Fill(T_Muon_NValidHitsSATrk->at(Mu1), factN);
	 }
	 
	 if ( passTightMuCuts(Mu2,0.01,0.02,0.1,0,0) ) { 
	   h_Dilep_TightMuon_TkLayers[1]->Fill(T_Muon_NLayers->at(Mu2), factN);
	   h_Dilep_TightMuon_StaHits[1]->Fill(T_Muon_NValidHitsSATrk->at(Mu2), factN);
	   }*/

	 iVertex    = SelectedVertexIndex();
	 newiVertex = SelectedVertexIndex(Mu1, factN);
	 
	 h_N_PV0_PVLep->Fill(newiVertex - iVertex);
	 
	 dZVertex = T_Vertex_z->at(iVertex) - T_Vertex_z->at(newiVertex);
	 h_N_dZ_PV0_PVLep->Fill(dZVertex);
	 
	 FillRelEff("Dilep", 0, Mu1, factN, iVertex, newiVertex);
	 FillRelEff("Dilep", 1, Mu2, factN, iVertex, newiVertex);

	 Filldz2D(Mu1, Mu2, factN, iVertex, newiVertex);	 
       }

       else if ( Signal=="MC_Wjets_S14" || Signal=="MC_Wjets_PU20bx25" ) {

	 double dR1 = 999;
	 double dR2 = 999;
	
	 if ( isMuMu || isTauMu) {
  
	   if (isMuMu) {
	     dR1 =  G_GEN_PromptMuon_4vec[0].DeltaR(G_Muon_4vec[0]);
	     dR2 =  G_GEN_PromptMuon_4vec[0].DeltaR(G_Muon_4vec[1]);
	   }
	   
	   if ( isTauMu ) {
	     dR1 =  G_GEN_PromptTauMuon_4vec[0].DeltaR(G_Muon_4vec[0]);
	     dR2 =  G_GEN_PromptTauMuon_4vec[0].DeltaR(G_Muon_4vec[1]);
	   }

	   if ( dR1 < 0.4 && dR2 >= 0.4 ) { 
	     Mu1 = 0; Mu2 = 1; }   
	   else if (dR2 < 0.4 && dR1 >= 0.4 ) {
	     Mu1 = 1; Mu2 = 0;}
	   else if ( dR1 < 0.4 && dR2 < 0.4 ) {
	     if (dR1 < dR2 ) { 
	        Mu1 = 0; Mu2 = 1;}
	     else {
	       Mu1 = 1; Mu2 = 0;}
	   }

	   double dRfake = 999;
	   int isFakeMatched = 0;

	   if (isNonPrompt) {
	     dRfake = G_GEN_Muon_4vec[0].DeltaR(G_Muon_4vec[Mu2]);
	     if (dRfake < 0.4) isFakeMatched = 1;	  
	   }

	   iVertex    = SelectedVertexIndex();
	   newiVertex = SelectedVertexIndex(Mu1, factN);

	   h_N_PV0_PVLep->Fill(newiVertex - iVertex);

	   dZVertex = T_Vertex_z->at(iVertex) - T_Vertex_z->at(newiVertex);
	   h_N_dZ_PV0_PVLep->Fill(dZVertex);

	   FillRelEff("Dilep", 0, Mu1, factN, iVertex, newiVertex);
	   FillRelEff("Dilep", 1, Mu2, factN, iVertex, newiVertex);

	   Filldz2D(Mu1, Mu2, factN, iVertex, newiVertex);

	   if ( isFakeMatched ) {

	     h_Dilep_Gen_Muon_MpdgId->Fill(T_Gen_Muon_MpdgId->at(0));
	     if (iVertex == newiVertex) h_Dilep_Gen_Muon_MpdgId_PV_Eq->Fill(T_Gen_Muon_MpdgId->at(0));
	     else if (iVertex != newiVertex) h_Dilep_Gen_Muon_MpdgId_PV_NEq->Fill(T_Gen_Muon_MpdgId->at(0));
	     
	   }
	 }
       }

       

       if (Signal=="MC_Wjets_8TeV") { 

	 double dR1 = 999;
	 double dR2 = 999;

	 
	 if (isMuMu) {
	  
	   dR1 =  G_GEN_PromptMuon_4vec[0].DeltaR(G_Muon_4vec[0]);
	   dR2 =  G_GEN_PromptMuon_4vec[0].DeltaR(G_Muon_4vec[1]);
	 
	   if ( dR1 < 0.4 && dR2 >= 0.4 ) { 
	     Mu1 = 0; Mu2 = 1; }   
	   else if (dR2 < 0.4 && dR1 >= 0.4 ) {
	     Mu1 = 1; Mu2 = 0;}
	   else if ( dR1 < 0.4 && dR2 < 0.4 ) {
	     if (dR1 < dR2 ) { 
	       Mu1 = 0; Mu2 = 1;}
	     else {
	       Mu1 = 1; Mu2 = 0;}
	   }
	 }

	 
	 /*if ( passTightMuCuts(Mu1,0.01,0.02,0.1,0,0) ) {  
	   h_Dilep_TightMuon_TkLayers[0]->Fill(T_Muon_NLayers->at(Mu1), factN);
	   h_Dilep_TightMuon_StaHits[0]->Fill(T_Muon_NValidHitsSATrk->at(Mu1), factN);
	 }
	 
	 if ( passTightMuCuts(Mu2,0.01,0.02,0.1,0,0 ) ) {
	   h_Dilep_TightMuon_TkLayers[1]->Fill(T_Muon_NLayers->at(Mu2), factN);
	   h_Dilep_TightMuon_StaHits[1]->Fill(T_Muon_NValidHitsSATrk->at(Mu2), factN);
	   }*/
	 
	 iVertex    = SelectedVertexIndex();
	 newiVertex = SelectedVertexIndex(Mu1, factN);
	 
	 h_N_PV0_PVLep->Fill(newiVertex - iVertex);
	 
	 dZVertex = T_Vertex_z->at(iVertex) - T_Vertex_z->at(newiVertex);
	 h_N_dZ_PV0_PVLep->Fill(dZVertex);

	 FillRelEff("Dilep", 0, Mu1, factN, iVertex, newiVertex);
	 FillRelEff("Dilep", 1, Mu2, factN, iVertex, newiVertex);

	 Filldz2D(Mu1, Mu2, factN, iVertex, newiVertex);
       }

       /*
       /// For tunning the Tight Muon ID cuts

       if(T_Muon_isPFMuon->at(0) && T_Muon_IsGlobalMuon->at(0) &&
	  T_Muon_isPFMuon->at(1) && T_Muon_IsGlobalMuon->at(1)) { 

	 h_N_Dilep_GLBPF_butTkLayers[0]->Fill(T_Muon_NLayers->at(0), factN);
	 h_N_Dilep_GLBPF_butTkLayers[1]->Fill(T_Muon_NLayers->at(1), factN);
    
	 h_N_Dilep_GLBPF_butSTAHits[0]->Fill(T_Muon_NValidHitsSATrk->at(0), factN);
	 h_N_Dilep_GLBPF_butSTAHits[1]->Fill(T_Muon_NValidHitsSATrk->at(1), factN);

       }

       if ( passTightMuCuts(0,0.2,0.2,0.5,5,0) && passTightMuCuts(1,0.2,0.2,0.5,5,0) ) 
	 h_N_Dilep_TigtMuCuts->Fill(1.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) ) 
	 h_N_Dilep_TigtMuCuts->Fill(2.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,6,0) && passTightMuCuts(1,0.01,0.02,0.1,6,0) ) 
	 h_N_Dilep_TigtMuCuts->Fill(3.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,7,0) && passTightMuCuts(1,0.01,0.02,0.1,7,0) ) 
	 h_N_Dilep_TigtMuCuts->Fill(4.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,5,7) && passTightMuCuts(1,0.01,0.02,0.1,5,7) ) 
	 h_N_Dilep_TigtMuCuts->Fill(5.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,6,7) && passTightMuCuts(1,0.01,0.02,0.1,6,7) ) 
	 h_N_Dilep_TigtMuCuts->Fill(6.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) 
	    && passPFIso(0) && passPFIso(1)) h_N_Dilep_TigtMuCuts->Fill(7.0,  factN);
       if ( passTightMuCuts(0,0.01,0.02,0.1,6,7) && passTightMuCuts(1,0.01,0.02,0.1,6,7) 
	    && passPFIso(0) && passPFIso(1)) h_N_Dilep_TigtMuCuts->Fill(8.0,  factN);

       if ( passTightMuCuts(0,0.01,0.02,0.1,0,0) && passTightMuCuts(1,0.01,0.02,0.1,0,0) ){ 
	 h_N_Dilep_TightMuCuts_butTkLayers[0]->Fill(T_Muon_NLayers->at(0), factN);
	 h_N_Dilep_TightMuCuts_butTkLayers[1]->Fill(T_Muon_NLayers->at(1), factN);
       }
       if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) ){ 
	 h_N_Dilep_TightMuCuts_butSTAHits[0]->Fill(T_Muon_NValidHitsSATrk->at(0), factN);
	 h_N_Dilep_TightMuCuts_butSTAHits[1]->Fill(T_Muon_NValidHitsSATrk->at(1), factN);
       }

       */




       /*if (G_Muon_HWW_ID[0] && G_Muon_HWW_ID[1] )      {

	  h_N_Dilep_TypeMu->Fill(1.0, factN);

	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_Dilep_TypeMu_LP->Fill(1.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_Dilep_TypeMu_HP->Fill(1.0, factN);

	  h_Dilep_HWWMu_PFIsoBeta_Mu1->Fill(G_Muon_PFIsoBeta[0], factN);
	  h_Dilep_HWWMu_PFIsoBeta_Mu2->Fill(G_Muon_PFIsoBeta[1], factN);
	}

	if (G_Muon_HWW_ISO[0] && G_Muon_HWW_ISO[1] )    {
	  h_N_Dilep_TypeMu->Fill(2.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_Dilep_TypeMu_LP->Fill(2.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_Dilep_TypeMu_HP->Fill(2.0, factN);
	  }*/

	if (G_Muon_TightID[0] && G_Muon_TightID[1] )    {
	  h_N_Dilep_TypeMu->Fill(3.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_Dilep_TypeMu_LP->Fill(3.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_Dilep_TypeMu_HP->Fill(3.0, factN);


	  //------>  Plots after Tight Muon ID at dilepton level
	  if ( isMuMu || isTauMu || isTauTau) { 
	    h_Dilep_TightMu_pt[Mu1]->Fill(G_Muon_4vec[0].Perp(), factN);
	    h_Dilep_TightMu_pt[Mu2]->Fill(G_Muon_4vec[1].Perp(), factN);
	    h_Dilep_TightMu_eta[Mu1]->Fill(G_Muon_4vec[0].Eta(), factN);
	    h_Dilep_TightMu_eta[Mu2]->Fill(G_Muon_4vec[1].Eta(), factN);
	    h_Dilep_TightMu_PFIsoBeta[Mu1]->Fill(G_Muon_PFIsoBeta[0], factN);
	    h_Dilep_TightMu_PFIsoBeta[Mu2]->Fill(G_Muon_PFIsoBeta[1], factN);
	    h_Dilep_TightMu_PFCH[Mu1]->Fill(G_Muon_PFChargedH[0], factN);
	    h_Dilep_TightMu_PFCH[Mu2]->Fill(G_Muon_PFChargedH[1], factN);
	    h_Dilep_TightMu_PFNH[Mu1]->Fill(G_Muon_PFNeutralH[0], factN);
	    h_Dilep_TightMu_PFNH[Mu2]->Fill(G_Muon_PFNeutralH[1], factN);
	    h_Dilep_TightMu_PFPh[Mu1]->Fill(G_Muon_PFPhoton[0], factN);
	    h_Dilep_TightMu_PFPh[Mu2]->Fill(G_Muon_PFPhoton[1], factN);
	    h_Dilep_TightMu_PFRho[Mu1]->Fill(G_Muon_PFRho[0], factN);
	    h_Dilep_TightMu_PFRho[Mu2]->Fill(G_Muon_PFRho[1], factN);
	  }

	}

	if (G_Muon_TightISO[0] && G_Muon_TightISO[1] )  {
	  h_N_Dilep_TypeMu->Fill(4.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_Dilep_TypeMu_LP->Fill(4.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_Dilep_TypeMu_HP->Fill(4.0, factN);

	  //------>  Plots after Tight Muon ID+ISO at dilepton level
	  if ( isMuMu || isTauMu || isTauTau) { 
	    h_Dilep_TightMuISO_pt[Mu1]->Fill(G_Muon_4vec[0].Perp(), factN);
	    h_Dilep_TightMuISO_pt[Mu2]->Fill(G_Muon_4vec[1].Perp(), factN);
	    h_Dilep_TightMuISO_eta[Mu1]->Fill(G_Muon_4vec[0].Eta(), factN);
	    h_Dilep_TightMuISO_eta[Mu2]->Fill(G_Muon_4vec[1].Eta(), factN);
	  }

	}

	/*
	
	//--------------------------------------------------------------------------------
	// SELECTION:: WW level selection
	//--------------------------------------------------------------------------------
	if (passesWWSelection(0, 1, 0)) {
	
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_WWlevel_TypeMu_LP->Fill(0.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_WWlevel_TypeMu_HP->Fill(0.0, factN);
		
	  
	  //------>  Match to a GEN Prompt Muons
	  if ( isMuMu || isTauMu || isTauTau) { 
	    FillRelEff("WWlevel", 0, Mu1, factN);
	    FillRelEff("WWlevel", 1, Mu2, factN);
	  }
	  

	  if(T_Muon_isPFMuon->at(0) && T_Muon_IsGlobalMuon->at(0) &&
	     T_Muon_isPFMuon->at(1) && T_Muon_IsGlobalMuon->at(1)) {
	   
	    h_N_WWlevel_TypeMu->Fill(0.0, factN);  
	    h_N_WWlevel_TigtMuCuts->Fill(0.0,  factN);
	  }

	/// For tunning the Tight Muon ID cuts

	  if ( isMuMu || isTauMu || isTauTau) { 

	    if ( passTightMuCuts(0,0.2,0.2,0.5,5,0) && passTightMuCuts(1,0.2,0.2,0.5,5,0) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(1.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(2.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,6,0) && passTightMuCuts(1,0.01,0.02,0.1,6,0) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(3.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,7,0) && passTightMuCuts(1,0.01,0.02,0.1,7,0) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(4.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,5,7) && passTightMuCuts(1,0.01,0.02,0.1,5,7) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(5.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,6,7) && passTightMuCuts(1,0.01,0.02,0.1,6,7) ) 
	      h_N_WWlevel_TigtMuCuts->Fill(6.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) 
		 && passPFIso(0) && passPFIso(1)) h_N_WWlevel_TigtMuCuts->Fill(7.0,  factN);
	    if ( passTightMuCuts(0,0.01,0.02,0.1,6,7) && passTightMuCuts(1,0.01,0.02,0.1,6,7) 
		 && passPFIso(0) && passPFIso(1)) h_N_WWlevel_TigtMuCuts->Fill(8.0,  factN);
	    
	    if ( passTightMuCuts(0,0.01,0.02,0.1,0,0) && passTightMuCuts(1,0.01,0.02,0.1,0,0) ){ 
	      h_N_WWlevel_TightMuCuts_butTkLayers[0]->Fill(T_Muon_NLayers->at(0), factN);
	      h_N_WWlevel_TightMuCuts_butTkLayers[1]->Fill(T_Muon_NLayers->at(1), factN);
	    }
	    if ( passTightMuCuts(0,0.01,0.02,0.1,5,0) && passTightMuCuts(1,0.01,0.02,0.1,5,0) ){ 
	      h_N_WWlevel_TightMuCuts_butSTAHits[0]->Fill(T_Muon_NValidHitsSATrk->at(0), factN);
	      h_N_WWlevel_TightMuCuts_butSTAHits[1]->Fill(T_Muon_NValidHitsSATrk->at(1), factN);
	    }

	  }

	}


	if (G_Muon_HWW_ID[0] && G_Muon_HWW_ID[1] && passesWWSelection(0, 1, 0))      {
	  h_N_WWlevel_TypeMu->Fill(1.0, factN);  
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_WWlevel_TypeMu_LP->Fill(1.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_WWlevel_TypeMu_HP->Fill(1.0, factN);
  
	  h_WWlevel_HWWMu_PFIsoBeta_Mu1->Fill(G_Muon_PFIsoBeta[0], factN);
	  h_WWlevel_HWWMu_PFIsoBeta_Mu2->Fill(G_Muon_PFIsoBeta[1], factN);

	}
	if (G_Muon_HWW_ISO[0] && G_Muon_HWW_ISO[1] && passesWWSelection(0, 1, 0)) {
	  h_N_WWlevel_TypeMu->Fill(2.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_WWlevel_TypeMu_LP->Fill(2.0, factN);  
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_WWlevel_TypeMu_HP->Fill(2.0, factN);
	}

      
	if (G_Muon_TightID[0] && G_Muon_TightID[1] && passesWWSelection(0, 1, 0))    {
	  
	  h_N_WWlevel_TypeMu->Fill(3.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_WWlevel_TypeMu_LP->Fill(3.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_WWlevel_TypeMu_HP->Fill(3.0, factN);


	  //------>  Plots after Tight Muon ID at WW level
	  if ( isMuMu || isTauMu || isTauTau) { 
	    h_WWlevel_TightMu_pt[Mu1]->Fill(G_Muon_4vec[0].Perp(), factN);
	    h_WWlevel_TightMu_pt[Mu2]->Fill(G_Muon_4vec[1].Perp(), factN);
	    h_WWlevel_TightMu_eta[Mu1]->Fill(G_Muon_4vec[0].Eta(), factN);
	    h_WWlevel_TightMu_eta[Mu2]->Fill(G_Muon_4vec[1].Eta(), factN);
	    h_WWlevel_TightMu_PFIsoBeta[Mu1]->Fill(G_Muon_PFIsoBeta[0], factN);
	    h_WWlevel_TightMu_PFIsoBeta[Mu2]->Fill(G_Muon_PFIsoBeta[1], factN);
	  }
	}

	if (G_Muon_TightISO[0] && G_Muon_TightISO[1] && passesWWSelection(0, 1, 0))  {
	  h_N_WWlevel_TypeMu->Fill(4.0, factN);
	  if ( G_Muon_4vec[0].Perp() <= 20 && G_Muon_4vec[1].Perp() <= 20) h_N_WWlevel_TypeMu_LP->Fill(4.0, factN);
	  if ( G_Muon_4vec[0].Perp() > 20 && G_Muon_4vec[1].Perp() > 20) h_N_WWlevel_TypeMu_HP->Fill(4.0, factN);

	  //------>  Plots after Tight Muon ID+ISO at WW level
	  if ( isMuMu || isTauMu || isTauTau) { 
	    h_WWlevel_TightMuISO_pt[Mu1]->Fill(G_Muon_4vec[0].Perp(), factN);
	    h_WWlevel_TightMuISO_pt[Mu2]->Fill(G_Muon_4vec[1].Perp(), factN);
	    h_WWlevel_TightMuISO_eta[Mu1]->Fill(G_Muon_4vec[0].Eta(), factN);
	    h_WWlevel_TightMuISO_eta[Mu2]->Fill(G_Muon_4vec[1].Eta(), factN);
	    }
	    }
	    
	*/
      }
      
      
    }
  }
  
} // end inside Loop



//------------------------------------------------------------------------------
// Get All Muons for HWW 2012 analysis
//------------------------------------------------------------------------------


void muonAnalyzer::GetAllHWWMuons() {

 
  UInt_t _muonSize = 0;

  _muonSize = T_Muon_Px->size();
  
  
  if ( _muonSize > 0 ) {  // asking for at least one muon in the event 

    if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get HWW Muons " << std::endl;

    for (unsigned int i = 0; i < _muonSize; i++) {
      
      /// *****  1   ***** Define selection for numerator and denominator, and general Muon ID


      bool isMuonID = false;
      bool isMuonISO = false;
      bool NoSTAMuon = true;
      
      const int NFLAGS = 10;
      bool muon_sel[NFLAGS];
     
      
      for (int j=0; j<NFLAGS; ++j) 	muon_sel[j] = false;
     
      
      //if( ( T_Muon_IsAllStandAloneMuons->at(i) && !T_Muon_IsGlobalMuon->at(i) )        &&  
      //  ( T_Muon_IsAllStandAloneMuons->at(i) && !T_Muon_IsAllTrackerMuons->at(i) ) )
      //	NoSTAMuon = false;

      if ( ( T_Muon_IsGlobalMuon->at(i) == true && T_Muon_NValidHitsSATrk->at(i) > 0 &&
	     T_Muon_NormChi2GTrk->at(i) < 10 && T_Muon_NumOfMatchedStations->at(i) > 1 ) ||
	   ( T_Muon_IsAllTrackerMuons->at(i) && T_Muon_IsTrackerMuonArbitrated->at(i) ) )
	muon_sel[0] = true;
       
      
      if (T_Muon_isPFMuon->at(i))
	muon_sel[1] = true;
      

      if (  G_Muon_4vec[i].Perp() > 10 &&  T_Muon_trkKink->at(i) < 20) 
	muon_sel[2] = true;

	
      if ( fabs(G_Muon_4vec[i].Eta()) < 2.4)
	muon_sel[3] = true; 


      //++++ OPTIMIZED AT LOW PT
      //if ( (G_Muon_4vec[i].Perp() < 20 &&  fabs(T_Muon_IP2DBiasedPV->at(i)) < 0.01) ||
      //   ( G_Muon_4vec[i].Perp() >= 20  && fabs(T_Muon_IP2DBiasedPV->at(i)) < 0.02) ) 
      //	muon_sel[4] = true;	  
	
      if ( T_Muon_NLayers->at(i) > 5 ) 
	muon_sel[4] = true; 

      if (T_Muon_NValidPixelHitsInTrk->at(i) > 0 ) 
	muon_sel[5] = true; 
           

      //bool matchPVmu= false;
      
	//if ( fabs(T_Muon_dzPVBiasedPV->at(i)) < 0.1) matchPVmu= true;

      //++++ OPTIMIZED AT LOW PT
      //      if ( (G_Muon_4vec[i].Perp() < 20 &&  fabs(T_Muon_dxyBestTrack->at(i)) < 0.01) ||
      //	   ( G_Muon_4vec[i].Perp() >= 20  && fabs(T_Muon_dxyBestTrack->at(i)) < 0.02) ) 
      Double_t dxy = sqrt(T_Muon_vx->at(i)*T_Muon_vx->at(i)+T_Muon_vy->at(i)*T_Muon_vy->at(i));

      if ( (G_Muon_4vec[i].Perp() < 20 &&  T_Muon_IPwrtAveBSInTrack->at(i)  < 0.01) ||
      	   ( G_Muon_4vec[i].Perp() >= 20  && T_Muon_IPwrtAveBSInTrack->at(i)  < 0.02) ) 
	muon_sel[6] = true;	  
	
      bool matchPVmu= false;
      
      //if ( fabs(T_Muon_dzBestTrack->at(i)) < 0.1) matchPVmu= true;
    
      int iVertex = SelectedVertexIndex();

      if ( iVertex >= 0 && fabs(T_Muon_vz->at(i) - T_Vertex_z->at(iVertex)) < 0.1) matchPVmu= true;

      if ( ((T_Muon_deltaPt->at(i))/(G_Muon_4vec[i].Perp())) < 0.1 ) 
	muon_sel[7] = true;
      

	///---Include also the requirement on the MVA output! 
	/*
	bool isMVAtight = false; 

	if ( (fabs(G_Muon_4vec[i].Eta()) < 1.479 && G_Muon_4vec[i].Perp() > 20 && T_Muon_MVARings->at(i) > 0.82) ||
	     ( fabs(G_Muon_4vec[i].Eta()) >= 1.479 && G_Muon_4vec[i].Perp() > 20 && T_Muon_MVARings->at(i) > 0.86) ||
	     ( fabs(G_Muon_4vec[i].Eta()) < 1.479 && G_Muon_4vec[i].Perp() <= 20 && T_Muon_MVARings->at(i) > 0.86) ||
	     ( fabs(G_Muon_4vec[i].Eta()) >= 1.479 && G_Muon_4vec[i].Perp() <= 20 &&  T_Muon_MVARings->at(i)> 0.82) )  
	  isMVAtight = true; 
	*/


      
	double isPFRelISo = (T_Muon_chargedHadronIsoR03->at(i)+T_Muon_neutralHadronIsoR03->at(i)+T_Muon_neutralHadronIsoR03->at(i))/G_Muon_4vec[i].Perp();
      
	double isPFRelISoBeta = ( T_Muon_chargedHadronIsoR03->at(i) + max(0., T_Muon_neutralHadronIsoR03->at(i) + T_Muon_photonIsoR03->at(i) - 0.5 * T_Muon_sumPUPtR03->at(i)) )/ G_Muon_4vec[i].Pt();
     
      if ( isPFRelISoBeta <  0.12)	muon_sel[8] = true;	  


	// Define the VBTF muon ID
       	isMuonID = muon_sel[0]*muon_sel[1]*muon_sel[2]*muon_sel[3]*muon_sel[4]*muon_sel[5]*muon_sel[6]*matchPVmu*muon_sel[7];
	
	// Define the muon ISO
	isMuonISO =  isMuonID*muon_sel[8];
       	
	//--> Classify muons
	
	// passing the HWW13 muon ID 
	G_Muon_HWW_ID.push_back(isMuonID);

	// passing the HWW13 muon ID+ISO 
	G_Muon_HWW_ISO.push_back(isMuonISO);

	G_Muon_PFIsoBeta.push_back(isPFRelISoBeta);
	G_Muon_PFChargedH.push_back(T_Muon_chargedHadronIsoR03->at(i));
	G_Muon_PFNeutralH.push_back(T_Muon_neutralHadronIsoR03->at(i)); 
	G_Muon_PFPhoton.push_back(T_Muon_photonIsoR03->at(i));
	G_Muon_PFRho.push_back(T_Muon_sumPUPtR03->at(i));

       	
	if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: after muon part" << std::endl;



    } // end loop on muons
  } // end loop on at least one muon


}





//------------------------------------------------------------------------------
// Get tight muon selection (from muon POG), 
//-----------------------------------------------------------------------------



void muonAnalyzer::GetAllTightMuons() {

 
  UInt_t muonSize = 0;

  muonSize = T_Muon_Px->size();
  
  
  if ( muonSize > 0 ) {  // asking for at least one muon in the event 
    
    if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get Tight Muons " << std::endl;

    for (unsigned int i = 0; i < muonSize; i++) {
      

      /// *****  1   ***** Define selection for numerator and denominator, and general Muon ID


      bool isMuonID = false;
      bool isMuonISO = false;
      bool NoSTAMuon = true;
      
      const int NFLAGS = 10;
      bool muon_sel[NFLAGS];
     
      for (int j=0; j<NFLAGS; ++j) 	muon_sel[j] = false;
      
      if(T_Muon_isPFMuon->at(i) && T_Muon_IsGlobalMuon->at(i)) 
	muon_sel[0] = true;

     if (G_Muon_4vec[i].Perp() > 10 &&  fabs(G_Muon_4vec[i].Eta()) < 2.4) 
	muon_sel[1] = true;
 
     if (T_Muon_NormChi2GTrk->at(i) < 10 ) 
	muon_sel[2] = true;

     if (T_Muon_NValidHitsSATrk->at(i) > 0 ) 
	muon_sel[3] = true;
     
     if (T_Muon_NumOfMatchedStations->at(i) > 1 )
	muon_sel[4] = true;

     if (T_Muon_NValidPixelHitsInTrk->at(i) > 0 ) 
	muon_sel[5] = true; 
 
     if ( T_Muon_NLayers->at(i) > 5 ) 
	muon_sel[6] = true; 
         
      
      
      //++++ OPTIMIZED AT LOW PT 
      //      if ( (G_Muon_4vec[i].Perp() < 20 &&  fabs(T_Muon_dxyBestTrack->at(i)) < 0.01) ||
      //	   ( G_Muon_4vec[i].Perp() >= 20  && fabs(T_Muon_dxyBestTrack->at(i)) < 0.02) ) 

      //Double_t dxy = sqrt(T_Muon_vx->at(i)*T_Muon_vx->at(i)+T_Muon_vy->at(i)*T_Muon_vy->at(i));

      //if ( (G_Muon_4vec[i].Perp() < 20 &&  dxy < 0.01) ||
      //	   ( G_Muon_4vec[i].Perp() >= 20  && dxy < 0.02) ) 

      if ( (G_Muon_4vec[i].Perp() < 20 &&  T_Muon_IPwrtAveBSInTrack->at(i)  < 0.01) ||
      	   ( G_Muon_4vec[i].Perp() >= 20  && T_Muon_IPwrtAveBSInTrack->at(i)  < 0.02) ) 
	muon_sel[7] = true;	  
	
      bool matchPVmu= false;
      
      //if ( fabs(T_Muon_dzBestTrack->at(i)) < 0.1) matchPVmu= true;
      //if ( fabs(T_Muon_vz->at(i)) < 0.1) matchPVmu= true;
      int iVertex = SelectedVertexIndex();
      if ( iVertex >= 0 && fabs(T_Muon_vz->at(i) - T_Vertex_z->at(iVertex)) < 0.1) matchPVmu= true;



      double isPFRelISo = (T_Muon_chargedHadronIsoR03->at(i)+T_Muon_neutralHadronIsoR03->at(i)+T_Muon_neutralHadronIsoR03->at(i))/G_Muon_4vec[i].Perp();
      double isPFRelISoBeta = ( T_Muon_chargedHadronIsoR03->at(i) + max(0., T_Muon_neutralHadronIsoR03->at(i) + T_Muon_photonIsoR03->at(i) - 0.5 * T_Muon_sumPUPtR03->at(i)) )/ G_Muon_4vec[i].Pt();
     
      if ( isPFRelISoBeta <  0.12)	muon_sel[8] = true;	  

      //if ( T_Muon_chargedHadronIsoR03->at(i)  <  0.12)	muon_sel[8] = true;	

      // Define the VBTF muon ID
      isMuonID = muon_sel[0]*muon_sel[1]*muon_sel[2]*muon_sel[3]*muon_sel[4]*muon_sel[5]*muon_sel[6]*muon_sel[7]*matchPVmu;
	
      // Define the muon ISO
      isMuonISO =  isMuonID*muon_sel[8];
      
      //--> Classify muons
      
      // passing the HWW13 muon ID 
      G_Muon_TightID.push_back(isMuonID);
      
      // passing the HWW13 muon ID+ISO 
      G_Muon_TightISO.push_back(isMuonISO);


       	
      if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: after muon part" << std::endl;


      
    } // end loop on muons
  } // end loop on at least one muon


}


//------------------------------------------------------------------------------
// Pass PF isolation ?? 
//-----------------------------------------------------------------------------

bool muonAnalyzer::passPFIso (int iMu) {

  bool passIso = false;

  double isPFRelISo = (T_Muon_chargedHadronIsoR03->at(iMu)+T_Muon_neutralHadronIsoR03->at(iMu)+T_Muon_neutralHadronIsoR03->at(iMu))/G_Muon_4vec[iMu].Perp();
  double isPFRelISoBeta = ( T_Muon_chargedHadronIsoR03->at(iMu) + max(0., T_Muon_neutralHadronIsoR03->at(iMu) + T_Muon_photonIsoR03->at(iMu) - 0.5 * T_Muon_sumPUPtR03->at(iMu)) )/ G_Muon_4vec[iMu].Pt();
     
  if ( isPFRelISoBeta <  0.12)   passIso = true;	  


  return passIso;

}


//------------------------------------------------------------------------------
// Function to tune TightMu ID variables
//-----------------------------------------------------------------------------

 bool muonAnalyzer::passTightMuCuts(int iMu,
				    float cutdxyLP, 
				    float cutdxyHP, 
				    float cutdz, 
				    int cutTkLayers, 
				    int cutMuonHits) {

  bool isMuonID = false;

  bool matchPVmu= false;

  const int NFLAGS = 10;
  bool muon_sel[NFLAGS];
  for (int j=0; j<NFLAGS; ++j) 	muon_sel[j] = false;
 
  UInt_t muonSize = 0;
  muonSize = T_Muon_Px->size();
 
  if ( muonSize > 0 ) {  // asking for at least one muon in the event 
    
    if (G_Debug_DefineAnalysisVariables) std::cout << "[DefineAnalysisVariables]: get Tight Muons " << std::endl;

    for (unsigned int i = 0; i < muonSize; i++) {
      
      /// *****  1   ***** Define selection for numerator and denominator, and general Muon ID
          
      if(T_Muon_isPFMuon->at(iMu) && T_Muon_IsGlobalMuon->at(iMu)) 
	muon_sel[0] = true;

     if (G_Muon_4vec[iMu].Perp() > 10 &&  fabs(G_Muon_4vec[iMu].Eta()) < 2.4) 
	muon_sel[1] = true;
 
     if (T_Muon_NormChi2GTrk->at(iMu) < 10 ) 
	muon_sel[2] = true;

     if (T_Muon_NValidHitsSATrk->at(iMu) > cutMuonHits) 
	muon_sel[3] = true;
     
     if (T_Muon_NumOfMatchedStations->at(iMu) > 1 )
	muon_sel[4] = true;

     if (T_Muon_NValidPixelHitsInTrk->at(iMu) > 0 ) 
	muon_sel[5] = true; 
 
     if ( T_Muon_NLayers->at(iMu) > cutTkLayers ) 
	muon_sel[6] = true; 
         
      
      
      //++++ OPTIMIZED AT LOW PT 
      //      if ( (G_Muon_4vec[iMu].Perp() < 20 &&  fabs(T_Muon_dxyBestTrack->at(iMu)) < 0.01) ||
      //	   ( G_Muon_4vec[iMu].Perp() >= 20  && fabs(T_Muon_dxyBestTrack->at(iMu)) < 0.02) ) 

      //Double_t dxy = sqrt(T_Muon_vx->at(iMu)*T_Muon_vx->at(iMu)+T_Muon_vy->at(iMu)*T_Muon_vy->at(iMu));

      //if ( (G_Muon_4vec[iMu].Perp() < 20 &&  dxy < 0.01) ||
      //	   ( G_Muon_4vec[iMu].Perp() >= 20  && dxy < 0.02) ) 

      if ( (G_Muon_4vec[iMu].Perp() < 20 &&  T_Muon_IPwrtAveBSInTrack->at(iMu)  < cutdxyLP) ||
      	   ( G_Muon_4vec[iMu].Perp() >= 20  && T_Muon_IPwrtAveBSInTrack->at(iMu)  < cutdxyHP ) ) 
	muon_sel[7] = true;	  
	
      
      //if ( fabs(T_Muon_dzBestTrack->at(iMu)) < 0.1) matchPVmu= true;
      //if ( fabs(T_Muon_vz->at(iMu)) < 0.1) matchPVmu= true;
      int iVertex = SelectedVertexIndex();
      if ( iVertex >= 0 && fabs(T_Muon_vz->at(iMu) - T_Vertex_z->at(iVertex)) < cutdz) matchPVmu= true;
    }
  }
  
  // Define the VBTF muon ID
  isMuonID = muon_sel[0]*muon_sel[1]*muon_sel[2]*muon_sel[3]*muon_sel[4]*muon_sel[5]*muon_sel[6]*muon_sel[7]*matchPVmu;
	
  return isMuonID;    

 }


//------------------------------------------------------------------------------
// Get tight muon selection (from muon POG), 
//-----------------------------------------------------------------------------

 void muonAnalyzer::FillRelEff(string levelCut, int indexMuon, int iMu, double weight, int _iVertex, int _newiVertex) {


  //  cout << _iVertex << "  " <<  _newiVertex << endl;

  double _dz = 999;
  if (_iVertex >= 0 ) _dz = fabs(get_dz(iMu,_iVertex));
  double _newdz = 999;
  if (_newiVertex >= 0 ) _newdz = fabs(get_dz(iMu,_newiVertex));


  if ( levelCut == "Dilep") { 

    //h_Dilep_TightMu_RelEff[indexMuon]->Fill(0.0, weight);

    if(T_Muon_IsGlobalMuon->at(iMu) && T_Muon_isPFMuon->at(iMu)) {

      h_Dilep_dz[indexMuon]->Fill(_dz);
      h_Dilep_dzMu[indexMuon]->Fill(_newdz);    
      h_Dilep_dz_BestTrack[indexMuon]->Fill(fabs(T_Muon_dzBestTrack->at(iMu)));

      if (indexMuon == 1) h_Dilep_dz_GTrack[indexMuon]->Fill(fabs(T_Muon_dzGTrack->at(iMu)), weight);
      h_Dilep_dz_InTrack[indexMuon]->Fill(fabs(T_Muon_dzInTrack->at(iMu)), weight);

    }
    
    if (_iVertex == _newiVertex) {
      
      h_Dilep_dz_PV_Eq[indexMuon]->Fill(_dz, weight);
      h_Dilep_dzMu_PV_Eq[indexMuon]->Fill(_newdz, weight);
      
      if (indexMuon == 0) GetAllJets(1, weight);
      
    }
    
    else if (_iVertex != _newiVertex) {
      
      h_Dilep_dz_PV_NEq[indexMuon]->Fill(_dz, weight);
      h_Dilep_dzMu_PV_NEq[indexMuon]->Fill(_newdz, weight);
      
      if (indexMuon == 0) GetAllJets(0, weight);

    }

    if(T_Muon_isPFMuon->at(iMu) && T_Muon_IsGlobalMuon->at(iMu)) {

      h_Dilep_TightMu_RelEff[indexMuon]->Fill(1, weight);
      h_Dilep_Chi2[indexMuon]->Fill(T_Muon_NormChi2GTrk->at(iMu), weight);
      h_Dilep_StaHits[indexMuon]->Fill(T_Muon_NValidHitsSATrk->at(iMu), weight);
      h_Dilep_StaNStation[indexMuon]->Fill(T_Muon_NumOfMatchedStations->at(iMu), weight);    
      h_Dilep_PixelHits[indexMuon]->Fill(T_Muon_NValidPixelHitsInTrk->at(iMu), weight); 
      h_Dilep_TkLayers[indexMuon]->Fill(T_Muon_NLayers->at(iMu), weight);
      h_Dilep_dxy[indexMuon]->Fill(T_Muon_IPwrtAveBSInTrack->at(iMu), weight);



      h_Dilep_StaHitsEta[indexMuon]->Fill(G_Muon_4vec[iMu].Eta(), T_Muon_NValidHitsSATrk->at(iMu), weight);
      h_Dilep_StaHitsPV[indexMuon]->Fill(T_Vertex_z->size(), T_Muon_NValidHitsSATrk->at(iMu), weight);

      h_Dilep_StaNStationEta[indexMuon]->Fill(G_Muon_4vec[iMu].Eta(), T_Muon_NumOfMatchedStations->at(iMu), weight);    
      h_Dilep_StaNStationPV[indexMuon]->Fill(T_Vertex_z->size(), T_Muon_NumOfMatchedStations->at(iMu), weight);    


      if(  T_Muon_NormChi2GTrk->at(iMu) < 10 ) {
	
	h_Dilep_TightMu_RelEff[indexMuon]->Fill(2, weight);
	
	if ( T_Muon_NValidHitsSATrk->at(iMu) > 0 ) {
	  
	  h_Dilep_TightMu_RelEff[indexMuon]->Fill(3, weight);
	  
	  if ( T_Muon_NumOfMatchedStations->at(iMu) > 1 ) {
	    
	    h_Dilep_TightMu_RelEff[indexMuon]->Fill(4, weight);
	    
	    if (T_Muon_NValidPixelHitsInTrk->at(iMu) > 0 ) { 
	      
	      h_Dilep_TightMu_RelEff[indexMuon]->Fill(5, weight);

	      /*
	      //Study NLayers cut 
	      for ( int c=1; c < 11; c++ ) {

		if ( T_Muon_NLayers->at(iMu) > c ) 
		}*/

	      if ( T_Muon_NLayers->at(iMu) > 5 ) {
		
		h_Dilep_TightMu_RelEff[indexMuon]->Fill(6, weight);

		h_Dilep_dz_bf_dy[indexMuon]->Fill(_dz, weight);
		h_Dilep_dzMu_bf_dy[indexMuon]->Fill(_newdz, weight);		
		h_Dilep_dz_BestTrack_bf_dy[indexMuon]->Fill(fabs(T_Muon_dzBestTrack->at(iMu)), weight);
		
		if ( (G_Muon_4vec[indexMuon].Perp() < 20 &&  T_Muon_IPwrtAveBSInTrack->at(iMu)  < 0.01) ||
		     ( G_Muon_4vec[indexMuon].Perp() >= 20  && T_Muon_IPwrtAveBSInTrack->at(iMu)  < 0.02) ) { 
		  
		  h_Dilep_TightMu_RelEff[indexMuon]->Fill(7, weight);
		  
		  if ( _dz!=999 && _dz < 0.1) { //&& ( ( indexMuon == 0 && _dz < 0.1 ) || ( indexMuon == 1 && _dz < 0.05 ) ) ) {

		    h_Dilep_TightMu_RelEff[indexMuon]->Fill(8, weight); 
		    
		  }}}}}}}}
  }

if ( levelCut == "WWlevel") { 

    if(T_Muon_isPFMuon->at(iMu) && T_Muon_IsGlobalMuon->at(iMu)) {

      h_WWlevel_Chi2[indexMuon]->Fill(T_Muon_NormChi2GTrk->at(iMu), weight);
      h_WWlevel_StaHits[indexMuon]->Fill(T_Muon_NValidHitsSATrk->at(iMu), weight);
      h_WWlevel_StaNStation[indexMuon]->Fill(T_Muon_NumOfMatchedStations->at(iMu), weight);    
      h_WWlevel_PixelHits[indexMuon]->Fill(T_Muon_NValidPixelHitsInTrk->at(iMu), weight); 
      h_WWlevel_TkLayers[indexMuon]->Fill(T_Muon_NLayers->at(iMu), weight);
      h_WWlevel_dxy[indexMuon]->Fill(T_Muon_IPwrtAveBSInTrack->at(iMu), weight);
      h_WWlevel_dz[indexMuon]->Fill(_dz, weight);

    }
 }



}



//------------------------------------------------------------------------------
// Get All Jets in the events
//------------------------------------------------------------------------------

void muonAnalyzer::GetAllJets(int PV_Eq, double weight) {

  int sizeJet = 0; 
  sizeJet =  T_JetAKCHS_Px->size(); 
 
  Int_t jetPt = 30;
  Int_t jetEta = 5;

  Int_t Njets = 0;
  
  for (int j = 0; j < sizeJet; j++) {

      G_Jet_4vec.push_back(TLorentzVector(T_JetAKCHS_Px->at(j),T_JetAKCHS_Py->at(j),T_JetAKCHS_Pz->at(j),T_JetAKCHS_Energy->at(j)));
   
      if ( G_Jet_4vec[j].Perp() < jetPt) continue;
      if ( G_Jet_4vec[j].Eta() > jetEta) continue;
      
      Njets++;

      h_Dilep_Jet_Energy->Fill(T_JetAKCHS_Energy->at(j), weight);

      if (PV_Eq == 1) {h_Dilep_Jet_Energy_PV_Eq->Fill(T_JetAKCHS_Energy->at(j), weight); }
      else            {h_Dilep_Jet_Energy_PV_NEq->Fill(T_JetAKCHS_Energy->at(j), weight);}


  }

  G_N_Jets = Njets;

  h_Dilep_N_Jets->Fill(Njets);

      if (PV_Eq == 1) {h_Dilep_N_Jets_PV_Eq->Fill(Njets); }
      else            {h_Dilep_N_Jets_PV_NEq->Fill(Njets);}

}

//------------------------------------------------------------------------------
// Filldz2D
//------------------------------------------------------------------------------
void muonAnalyzer::Filldz2D(int iMu1, int iMu2, double weight, int _iVertex, int _newiVertex)
{

  //Fill 2D histograms, Signal Efficiency histograms, and dilepton 1D histograms

  double _dz1 = 999.0;
  double _dz2 = 999.0;
  if (_iVertex >= 0 ) {
    _dz1 = fabs(get_dz(iMu1, _iVertex));
    _dz2 = fabs(get_dz(iMu2, _iVertex));
  }

  double _newdz1 = 999.0;
  double _newdz2 = 999.0;
  if (_newiVertex >= 0 ) {
    _newdz1 = fabs(get_dz(iMu1, _newiVertex));
    _newdz2 = fabs(get_dz(iMu2, _newiVertex));
  }

  double _dzBT1 = fabs(T_Muon_dzBestTrack->at(iMu1));
  double _dzBT2 = fabs(T_Muon_dzBestTrack->at(iMu2));

  if (T_Muon_isPFMuon->at(iMu1) && T_Muon_IsGlobalMuon->at(iMu1) && _dz1<999 && _newdz1<999 && _dzBT1<999) {
  if (T_Muon_isPFMuon->at(iMu2) && T_Muon_IsGlobalMuon->at(iMu2) && _dz2<999 && _newdz2<999 && _dzBT2<999) {
    // Applying GLB + PF Muon for both
      
      h_2D_Dilep_dz->Fill(_dz1, _dz2, weight);
      h_2D_Dilep_dzMu->Fill(_newdz1, _newdz2, weight);
      h_2D_Dilep_dzBT->Fill(_dzBT1, _dzBT2, weight);

      h_2D_Dilep_dz_Eff->Fill(-1,weight);
      h_2D_Dilep_dzMu_Eff->Fill(-1,weight);
      h_2D_Dilep_dzBT_Eff->Fill(-1,weight);
      
      if (_dz1<0.10)
	{
	  for (int i=1;i<=10;i++) {
	    if (_dz2<0.01*i) h_2D_Dilep_dz_Eff->Fill(i-1,weight);
	  }
	}

      if (_newdz1<0.10)
	{
	  for (int i=1;i<=10;i++) {
	    if (_newdz2<0.01*i) h_2D_Dilep_dzMu_Eff->Fill(i-1,weight);
	  }
	}

      if (_dzBT1<0.10)
	{
	  for (int i=1;i<=10;i++) {
	    if (_dzBT2<0.01*i) h_2D_Dilep_dzBT_Eff->Fill(i-1,weight);
	  }
	}

      h_TrueDilep_dz[0]->Fill(_dz1, weight);
      h_TrueDilep_dzMu[0]->Fill(_newdz1, weight);    
      h_TrueDilep_dz_BestTrack[0]->Fill(fabs(T_Muon_dzBestTrack->at(iMu1)), weight);
      h_TrueDilep_dz[1]->Fill(_dz2, weight);
      h_TrueDilep_dzMu[1]->Fill(_newdz2, weight);    
      h_TrueDilep_dz_BestTrack[1]->Fill(fabs(T_Muon_dzBestTrack->at(iMu2)), weight);
      
      if (_iVertex == _newiVertex) 
	{	
	  h_2D_Dilep_dz_PV_Eq->Fill(_dz1, _dz2, weight);
	  h_2D_Dilep_dzMu_PV_Eq->Fill(_newdz1, _newdz2, weight);
	  h_2D_Dilep_dzBT_PV_Eq->Fill(_dzBT1, _dzBT2, weight);	      
	}
      
      else if (_iVertex != _newiVertex) 
	{
	  h_2D_Dilep_dz_PV_NEq->Fill(_dz1, _dz2, weight);
	  h_2D_Dilep_dzMu_PV_NEq->Fill(_newdz1, _newdz2, weight);
	  h_2D_Dilep_dzBT_PV_NEq->Fill(_dzBT1, _dzBT2, weight);
	}

      if(T_Muon_NormChi2GTrk->at(iMu1)<10 && T_Muon_NValidHitsSATrk->at(iMu1)>0 && T_Muon_NumOfMatchedStations->at(iMu1)>1 && T_Muon_NValidPixelHitsInTrk->at(iMu1)>0 && T_Muon_NLayers->at(iMu1)>5) {
      if(T_Muon_NormChi2GTrk->at(iMu2)<10 && T_Muon_NValidHitsSATrk->at(iMu2)>0 && T_Muon_NumOfMatchedStations->at(iMu2)>1 && T_Muon_NValidPixelHitsInTrk->at(iMu2)>0 && T_Muon_NLayers->at(iMu2)>5) {

	//Applying Tight ID selection before dxy cut for both
	
	h_2D_Dilep_dz_bf_dy->Fill(_dz1, _dz2, weight);
	h_2D_Dilep_dzMu_bf_dy->Fill(_newdz1, _newdz2, weight);
	h_2D_Dilep_dzBT_bf_dy->Fill(_dzBT1, _dzBT2, weight);

	h_2D_Dilep_dz_bf_dy_Eff->Fill(-1,weight);
	h_2D_Dilep_dzMu_bf_dy_Eff->Fill(-1,weight);
	h_2D_Dilep_dzBT_bf_dy_Eff->Fill(-1,weight);
	
	if (_dz1<0.10)
	  {
	    for (int i=1;i<=10;i++) {
	      if (_dz2<0.01*i) h_2D_Dilep_dz_bf_dy_Eff->Fill(i-1,weight);
	    }
	  }
	
	if (_newdz1<0.10)
	  {
	    for (int i=1;i<=10;i++) {
	      if (_newdz2<0.01*i) h_2D_Dilep_dzMu_bf_dy_Eff->Fill(i-1,weight);
	    }
	  }
	
	if (_dzBT1<0.10)
	  {
	    for (int i=1;i<=10;i++) {
	      if (_dzBT2<0.01*i) h_2D_Dilep_dzBT_bf_dy_Eff->Fill(i-1,weight);
	    }
	  }
	

	h_TrueDilep_dz_bf_dy[0]->Fill(_dz1, weight);
	h_TrueDilep_dzMu_bf_dy[0]->Fill(_newdz1, weight);    
	h_TrueDilep_dz_BestTrack_bf_dy[0]->Fill(fabs(T_Muon_dzBestTrack->at(iMu1)), weight);
	h_TrueDilep_dz_bf_dy[1]->Fill(_dz2, weight);
	h_TrueDilep_dzMu_bf_dy[1]->Fill(_newdz2, weight);    
	h_TrueDilep_dz_BestTrack_bf_dy[1]->Fill(fabs(T_Muon_dzBestTrack->at(iMu2)), weight);
	
	if (_iVertex == _newiVertex) 
	  {	
	    h_2D_Dilep_dz_bf_dy_PV_Eq->Fill(_dz1, _dz2, weight);
	    h_2D_Dilep_dzMu_bf_dy_PV_Eq->Fill(_newdz1, _newdz2, weight);
	    h_2D_Dilep_dzBT_bf_dy_PV_Eq->Fill(_dzBT1, _dzBT2, weight);	      
	  }
	
	else if (_iVertex != _newiVertex) 
	  {
	    h_2D_Dilep_dz_bf_dy_PV_NEq->Fill(_dz1, _dz2, weight);
	    h_2D_Dilep_dzMu_bf_dy_PV_NEq->Fill(_newdz1, _newdz2, weight);
	    h_2D_Dilep_dzBT_bf_dy_PV_NEq->Fill(_dzBT1, _dzBT2, weight);
	  }

      }
      }

  }
  }

}

//------------------------------------------------------------------------------
// SelectedVertexIndex
//------------------------------------------------------------------------------
Int_t  muonAnalyzer::SelectedVertexIndex()
{

Int_t goodVertexIndex = -999;

Int_t nGoodVertex = 0;

for (UInt_t iVertex=0; iVertex<T_Vertex_z->size(); iVertex++) {

  if (fabs(T_Vertex_z ->at(iVertex)) < 24 &&
      T_Vertex_rho ->at(iVertex) < 2 &&
      T_Vertex_ndof ->at(iVertex) > 4 &&
      !T_Vertex_isFake->at(iVertex)) {
    nGoodVertex++;

    if (nGoodVertex == 1) goodVertexIndex = iVertex;
  }
 }

 return goodVertexIndex;

}


//------------------------------------------------------------------------------
// SelectedVertexIndex wrt to the closer Mu
//------------------------------------------------------------------------------

Int_t  muonAnalyzer::SelectedVertexIndex(int iMu, double weight) //--> Currently using this one
{
  
  Int_t newgoodVertexIndex = -999;
  
  Double_t maxdz = 999.0;
  Double_t dz    = 999.9;
  
  for (UInt_t iVertex=0; iVertex<T_Vertex_z->size(); iVertex++) 
    {
      
      if (fabs(T_Vertex_z ->at(iVertex)) < 24 &&
	  T_Vertex_rho ->at(iVertex) < 2 &&
	  T_Vertex_ndof ->at(iVertex) > 4 &&
	  !T_Vertex_isFake->at(iVertex)) 
	{
	  
	  dz = fabs(get_dz(iMu,iVertex));
	  
	  if (dz  <  maxdz) 
	    {
	      maxdz = dz;
	      newgoodVertexIndex = iVertex;
	    }
	  
	}
    }

  if(T_Muon_isPFMuon->at(iMu) && T_Muon_IsGlobalMuon->at(iMu)) h_Dilep_dz_GTrack[0]->Fill(maxdz);
  
  return newgoodVertexIndex;
  
  
}


Int_t  muonAnalyzer::SelectedVertexIndex(TString signal, int iMu) //--> Currently NOT using this one
{


  Int_t newgoodVertexIndex = -999;

  Double_t maxdz = 999.0;
  Double_t dz    = 999.9;
  
  if (signal=="MC_GGHWW_S14" || signal=="MC_GGHWW_PU20bx25" || signal=="MC_GGHWW_8TeV" || signal=="MC_DY_S14" || signal=="MC_DY_PU20bx25" || signal=="MC_DY_8TeV")
    {
  
      for (UInt_t iVertex=0; iVertex<T_Vertex_z->size(); iVertex++) {
	
	if (fabs(T_Vertex_z ->at(iVertex)) < 24 &&
	    T_Vertex_rho ->at(iVertex) < 2 &&
	    T_Vertex_ndof ->at(iVertex) > 4 &&
	    !T_Vertex_isFake->at(iVertex)) {
      
	  dz = fabs(T_Muon_vz->at(0) - T_Vertex_z->at(iVertex)) + fabs(T_Muon_vz->at(1) - T_Vertex_z->at(iVertex));
	  
	  if (dz  <  maxdz) 
	    {
	      maxdz = dz;
	      newgoodVertexIndex = iVertex;
	    }
	  
	}
      }
      
      return newgoodVertexIndex;
      
    }

  else if (signal=="MC_Wjets_S14" || signal=="MC_Wjets_PU20bx25" || signal=="MC_Wjets_8TeV")
    {
  
      for (UInt_t iVertex=0; iVertex<T_Vertex_z->size(); iVertex++) {
	
	if (fabs(T_Vertex_z ->at(iVertex)) < 24 &&
	    T_Vertex_rho ->at(iVertex) < 2 &&
	    T_Vertex_ndof ->at(iVertex) > 4 &&
	    !T_Vertex_isFake->at(iVertex)) {
      
	  dz = fabs(T_Muon_vz->at(iMu) - T_Vertex_z->at(iVertex));
	  
	  if (dz  <  maxdz) 
	    {
	      maxdz = dz;
	      newgoodVertexIndex = iVertex;
	    }
	  
	}
      }
      
      return newgoodVertexIndex;
      
    } 
  
}

//------------------------------------------------------------------------------
// Compute dz  
//------------------------------------------------------------------------------

 Double_t muonAnalyzer::get_dz (int iMu, int iVtx) { 

   double dz = 999; 

   double Vx = T_Vertex_x->at(iVtx);
   double Vy = T_Vertex_y->at(iVtx);
   double Vz = T_Vertex_z->at(iVtx);

   double vx = T_Muon_vx->at(iMu);
   double vy = T_Muon_vy->at(iMu);
   double vz = T_Muon_vz->at(iMu);

   double px = T_Muon_Px->at(iMu);
   double py = T_Muon_Py->at(iMu);
   double pz = T_Muon_Pz->at(iMu);
   double pt = T_Muon_Pt->at(iMu);
   double phi = G_Muon_4vec[iMu].Phi();

   /*  double vx = T_Muon_BestTrack_vx->at(iMu);
   double vy = T_Muon_BestTrack_vy->at(iMu);
   double vz = T_Muon_BestTrack_vz->at(iMu);

   double px = T_Muon_BestTrack_Px->at(iMu);
   double py = T_Muon_BestTrack_Py->at(iMu);
   double pz = T_Muon_BestTrack_Pz->at(iMu);
   double pt = T_Muon_BestTrack_Pt->at(iMu);
   double phi = T_Muon_BestTrack_Phi->at(iMu); */

   dz = (Vz - vz) - (((Vx - vx)*std::cos(float(phi)) + (Vy - vy)*std::sin(float(phi)))*(pz/pt));
   //dz = (vz - Vz) - (((vx-Vx)*px + (vy-Vy)*py)/pt * (pz/pt));

   return dz;
   
 };

//------------------------------------------------------------------------------
// Compute deltaR   
//------------------------------------------------------------------------------

 Double_t muonAnalyzer::getDeltaR (int iMu, int iVtx) { 

   double dR = 999; 

   double dx = T_Muon_vx->at(iMu) - T_Vertex_x->at(iVtx);
   double dy = T_Muon_vy->at(iMu) - T_Vertex_y->at(iVtx);
   double dz = T_Muon_vz->at(iMu) - T_Vertex_z->at(iVtx);

   dR = sqrt(dx*dx + dy*dy + dz*dz);

   return dR;

 } 

//------------------------------------------------------------------------------
// Compute MT   
//------------------------------------------------------------------------------

Double_t muonAnalyzer::giveMT(int index_Mu,double MET, double MET_Phi)
{

  // --> Transversal Mass ( muon, MET) 
  Double_t Pt_muon = G_Muon_4vec[index_Mu].Perp();
  Double_t Px_muon = T_Muon_Px->at(index_Mu);
  Double_t Py_muon = T_Muon_Py->at(index_Mu);
  Double_t Px_nu = cos(MET_Phi)*MET;
  Double_t Py_nu = sin(MET_Phi)*MET;
  Double_t Pt_nu = sqrt(Px_nu*Px_nu + Py_nu*Py_nu);
	  
  Double_t MT = sqrt(fabs((Pt_muon+Pt_nu)*(Pt_muon+Pt_nu) -(Px_muon+Px_nu)*(Px_muon+Px_nu)-(Py_muon+Py_nu)*(Py_muon+Py_nu)));

  return MT;
}



//------------------------------------------------------------------------------
// Compute generic deltaPhi
//------------------------------------------------------------------------------

float muonAnalyzer::DeltaPhi(float phi1, float phi2) {
  //  float pi = TMath::Pi();
  float result = fabs(phi1 - phi2);
  return result;
}



//------------------------------------------------------------------------------
// Compute min proyected MET  
//------------------------------------------------------------------------------

 float muonAnalyzer::projectedMET(int lep1, int lep2){
  
  
  float MET    = T_METPF_ET;
  float METPhi = T_METPF_Phi;


  float deltaPhiLep0MET = fabs(DeltaPhi(G_Muon_4vec[lep1].Phi(), METPhi));
  float deltaPhiLep1MET = fabs(DeltaPhi(G_Muon_4vec[lep2].Phi(), METPhi));
   
  float minDeltaPhiLepMET = deltaPhiLep0MET;
  if (deltaPhiLep1MET < minDeltaPhiLepMET) minDeltaPhiLepMET = deltaPhiLep1MET;
    
  float _projectedMET = MET;
  if (minDeltaPhiLepMET < 0.5 * TMath::Pi()) _projectedMET = MET * sin(minDeltaPhiLepMET);
  
  /*
  float ChargedMET    = GetMET(); //T_METChargedNeutralPFNoPU_ET;
  float ChargedMETPhi = GetMET_Phi(); //T_METChargedNeutralPFNoPU_Phi;
  
  //--------------- Projected ChargedMET
  float deltaPhiLep0ChargedMET = fabs(DeltaPhi(HypLep0.p.Phi(), ChargedMETPhi));
  float deltaPhiLep1ChargedMET = fabs(DeltaPhi(HypLep1.p.Phi(), ChargedMETPhi));
       
  float minDeltaPhiLepChargedMET = deltaPhiLep0ChargedMET;
  if (deltaPhiLep1ChargedMET < minDeltaPhiLepChargedMET) minDeltaPhiLepChargedMET = deltaPhiLep1ChargedMET;
  
  float projectedChargedMET = ChargedMET;
  if (minDeltaPhiLepChargedMET < 0.5 * TMath::Pi()) projectedChargedMET = ChargedMET * sin(minDeltaPhiLepChargedMET);

  float minMET = min(projectedChargedMET,projectedMET);
  */

  return _projectedMET;
}


//------------------------------------------------------------------------------
// Compute deltaPhi jets
//------------------------------------------------------------------------------

 float  muonAnalyzer::deltaPhiJet(int lep1, int lep2) {
 

  //  if (chan==MuMu || chan==ElEl){
    float maxJetEt = -999;
    int   leadJet = -1;
    int   nLeadJets = 0;
    
    for (UInt_t k=0; k<T_JetAKCHS_Energy->size(); k++) { 

      if (G_Jet_4vec[k].Pt() < 30)                  continue;
      if (fabs((G_Jet_4vec[k].Eta())) > 5)               continue;
      if (fabs((G_Jet_4vec[k].DeltaR(G_Muon_4vec[lep1]))) < 0.3) continue;
      if (fabs((G_Jet_4vec[k].DeltaR(G_Muon_4vec[lep2]))) < 0.3) continue;
	  
      if (G_Jet_4vec[k].Pt() > maxJetEt){
	maxJetEt  = G_Jet_4vec[k].Pt();
	leadJet   = k;
	nLeadJets++;
      }
    }

    if (nLeadJets == 0) return true;
    
    TLorentzVector LeadJet(T_JetAKCHS_Px->at(leadJet), T_JetAKCHS_Py->at(leadJet), T_JetAKCHS_Pz->at(leadJet), T_JetAKCHS_Energy->at(leadJet));
    TLorentzVector DiHypLep = G_Muon_4vec[lep1]+G_Muon_4vec[lep2];
    float deltaPhiLLJet = fabs(LeadJet.DeltaPhi(DiHypLep)*TMath::RadToDeg());
	  
    return deltaPhiLLJet;
  
 }


/*
//------------------------------------------------------------------------------
// Define soft muon 
//------------------------------------------------------------------------------

 bool muonAnalyzer::passesSoftMuonVeto(int lep1, int lep2){
  
  for (unsigned int k=0; k<T_Muon_Px->size(); k++) {

    if (HypLep0.type == 0 && HypLep0.index == (int) k) continue;
    if (HypLep1.type == 0 && HypLep1.index == (int) k) continue;
    TLorentzVector Mu(T_Muon_Px->at(k), T_Muon_Py->at(k), T_Muon_Pz->at(k), T_Muon_Energy->at(k));
    
    float isolation = 0.; //(T_Muon_SumIsoTrack->at(k) + T_Muon_SumIsoCalo->at(k)) / Mu.Pt();
    bool thereIsSoftMuon = false;
    if (Mu.Pt() > 3                                             &&
	((Mu.Pt() <= 20.) || (Mu.Pt() > 20 && isolation > 0.1)) &&
	T_Muon_IsAllTrackerMuons->at(k)                         &&
	T_Muon_IsTMLastStationAngTight->at(k)                   &&
	T_Muon_InnerTrackFound->at(k) > 10                      &&
	fabs(T_Muon_IP2DBiasedPV->at(k)) < 0.2                  &&
	fabs(T_Muon_dzPVBiasedPV->at(k)) > 0.1)  
      thereIsSoftMuon = true;
    
    if (thereIsSoftMuon) return false;
  }
#ifdef DEBUG
  cout << "passes SoftMuon Veto" <<endl;
#endif
  return true;
}
*/


//--------------------------------------------------------------------------------
//Compute pt of the dilepton system
//--------------------------------------------------------------------------------

float muonAnalyzer::ptDilepton(int lep1, int lep2){
  
  //  if (chan==MuMu || chan==ElEl){
  float ptdil = (G_Muon_4vec[lep1] + G_Muon_4vec[lep2]).Pt();
    

  return ptdil;

 }


//--------------------------------------------------------------------------------
//passed antibtaging 
//--------------------------------------------------------------------------------

bool muonAnalyzer::passesAntiBTagging(int lep1, int lep2){
  
  for (UInt_t k=0; k<T_JetAKCHS_Energy->size(); k++) {  // Different from jet veto. Why?

    if (G_Jet_4vec[k].Pt() < 10)                     continue;
    if (fabs(G_Jet_4vec[k].DeltaR(G_Muon_4vec[lep1])) < 0.3) continue;
    if (fabs(G_Jet_4vec[k].DeltaR(G_Muon_4vec[lep2])) < 0.3) continue;
    
    if (T_JetAKCHS_Tag_HighEffTC->at(k) > 2.1) return false;
  }

  return true;
}



//--------------------------------------------------------------------------------
// SELECTION:: WW level selection
//--------------------------------------------------------------------------------

bool muonAnalyzer::passesWWSelection(int lep1, int lep2, int jetCh){

bool pass = false;

double mass = (G_Muon_4vec[lep1] + G_Muon_4vec[lep2]).M();

 if ( T_Muon_Px->size() < 3 )  {  	       // No extra leptons above 10 GEV 
   
   if ( T_METPF_ET > 20 ) { 

     if ( mass > 12 ) {

       if ( abs(mass-91.1876) > 15 ) {          // Z veto cut 
 
	 if ( projectedMET(lep1,lep2) > 45 ) {  

	   //if ( deltaPhiLLJet(lep1,lep2)  < 160.0 ) {      // DeltaPhiLLJetJet
	   
	   if ( ptDilepton(lep1,lep2) > 30 ) { 

	     if ( passesAntiBTagging(lep1,lep2) ) {

	       if ( G_N_Jets == jetCh ) { 

		 pass = true;
	       }}}}}}}} 
 
 return pass;

}


void muonAnalyzer::SetDataMembersAtTermination() {
  // Get Data Members at the client-master (after finishing the analysis at the workers nodes)
  // Only data members set here will be accesible at the client-master


  ///*** 1D histos ***/// 


  h_N_dZ_PV0_PVLep = ((TH1F*) FindOutput("h_N_dZ_PV0_PVLep"));
  h_N_PV0_PVLep = ((TH1F*) FindOutput("h_N_PV0_PVLep"));

  h_N_PV = ((TH1F*) FindOutput("h_N_PV"));
  h_N_Dilep_TypeMu = ((TH1F*) FindOutput("h_N_Dilep_TypeMu"));
  h_N_Dilep_TypeMu_LP = ((TH1F*) FindOutput("h_N_Dilep_TypeMu_LP"));
  h_N_Dilep_TypeMu_HP = ((TH1F*) FindOutput("h_N_Dilep_TypeMu_HP"));
  h_N_WWlevel_TypeMu = ((TH1F*) FindOutput("h_N_WWlevel_TypeMu"));
  h_N_WWlevel_TypeMu_LP = ((TH1F*) FindOutput("h_N_WWlevel_TypeMu_LP"));
  h_N_WWlevel_TypeMu_HP = ((TH1F*) FindOutput("h_N_WWlevel_TypeMu_HP"));

  h_N_Dilep_TigtMuCuts = ((TH1F*) FindOutput("h_N_Dilep_TigtMuCuts"));
  h_N_WWlevel_TigtMuCuts = ((TH1F*) FindOutput("h_N_WWlevel_TigtMuCuts"));

  h_N_Dilep_TightMuCuts_butTkLayers[0] = ((TH1F*) FindOutput("h_N_Dilep_TightMuCuts_butTkLayers_Mu1"));
  h_N_Dilep_TightMuCuts_butTkLayers[1] = ((TH1F*) FindOutput("h_N_Dilep_TightMuCuts_butTkLayers_Mu2"));
  h_N_Dilep_TightMuCuts_butSTAHits[0] = ((TH1F*) FindOutput(" h_N_Dilep_TightMuCuts_butSTAHits_Mu1"));
  h_N_Dilep_TightMuCuts_butSTAHits[1] = ((TH1F*) FindOutput("h_N_Dilep_TightMuCuts_butSTAHits_Mu2"));

  h_N_WWlevel_TightMuCuts_butTkLayers[0] = ((TH1F*) FindOutput("h_N_WWlevel_TightMuCuts_butTkLayers_Mu1"));
  h_N_WWlevel_TightMuCuts_butTkLayers[1] = ((TH1F*) FindOutput("h_N_WWlevel_TightMuCuts_butTkLayers_Mu2"));
  h_N_WWlevel_TightMuCuts_butSTAHits[0] = ((TH1F*) FindOutput(" h_N_WWlevel_TightMuCuts_butSTAHits_Mu1"));
  h_N_WWlevel_TightMuCuts_butSTAHits[1] = ((TH1F*) FindOutput("h_N_WWlevel_TightMuCuts_butSTAHits_Mu2"));

  h_N_Dilep_GLBPF_butTkLayers[0] = ((TH1F*) FindOutput("h_N_Dilep_GLBPF_butTkLayers_Mu1"));
  h_N_Dilep_GLBPF_butTkLayers[1] = ((TH1F*) FindOutput("h_N_Dilep_GLBPF_butTkLayers_Mu2"));
  h_N_Dilep_GLBPF_butSTAHits[0] = ((TH1F*) FindOutput(" h_N_Dilep_GLBPF_butSTAHits_Mu1"));
  h_N_Dilep_GLBPF_butSTAHits[1] = ((TH1F*) FindOutput("h_N_Dilep_GLBPF_butSTAHits_Mu2"));

  h_N_WWlevel_GLBPF_butTkLayers[0] = ((TH1F*) FindOutput("h_N_WWlevel_GLBPF_butTkLayers_Mu1"));
  h_N_WWlevel_GLBPF_butTkLayers[1] = ((TH1F*) FindOutput("h_N_WWlevel_GLBPF_butTkLayers_Mu2"));
  h_N_WWlevel_GLBPF_butSTAHits[0] = ((TH1F*) FindOutput(" h_N_WWlevel_GLBPF_butSTAHits_Mu1"));
  h_N_WWlevel_GLBPF_butSTAHits[1] = ((TH1F*) FindOutput("h_N_WWlevel_GLBPF_butSTAHits_Mu2"));

  h_Dilep_AllMu_PFIsoBeta_Mu1 = ((TH1F*) FindOutput("h_Dilep_AllMu_PFIsoBeta_Mu1"));
  h_Dilep_AllMu_PFIsoBeta_Mu2 = ((TH1F*) FindOutput("h_Dilep_AllMu_PFIsoBeta_Mu2"));
  h_Dilep_HWWMu_PFIsoBeta_Mu1 = ((TH1F*) FindOutput("h_Dilep_HWWMu_PFIsoBeta_Mu1"));
  h_Dilep_HWWMu_PFIsoBeta_Mu2 = ((TH1F*) FindOutput("h_Dilep_HWWMu_PFIsoBeta_Mu2"));
  h_WWlevel_HWWMu_PFIsoBeta_Mu1 = ((TH1F*) FindOutput("h_WWlevel_HWWMu_PFIsoBeta_Mu1"));
  h_WWlevel_HWWMu_PFIsoBeta_Mu2 = ((TH1F*) FindOutput("h_WWlevel_HWWMu_PFIsoBeta_Mu2"));

  //------>  Plots after Tight Muon ID at dilepton level

  h_Dilep_TightMuon_TkLayers[0] = ((TH1F*) FindOutput("h_Dilep_TightMuon_TkLayers_Mu1"));
  h_Dilep_TightMuon_TkLayers[1] = ((TH1F*) FindOutput("h_Dilep_TightMuon_TkLayers_Mu2")); 
  h_Dilep_TightMuon_StaHits[0] = ((TH1F*) FindOutput("h_Dilep_TightMuon_StaHits_Mu1"));
  h_Dilep_TightMuon_StaHits[1] = ((TH1F*) FindOutput("h_Dilep_TightMuon_StaHits_Mu2")); 

  h_Dilep_TightMu_pt[0] = ((TH1F*) FindOutput("h_Dilep_TightMu_pt_Mu1"));
  h_Dilep_TightMu_pt[1] = ((TH1F*) FindOutput("h_Dilep_TightMu_pt_Mu2"));
  h_Dilep_TightMu_eta[0] = ((TH1F*) FindOutput("h_WWlevel_TightMu_eta_Mu1"));
  h_Dilep_TightMu_eta[1] = ((TH1F*) FindOutput("h_WWlevel_TightMu_eta_Mu2"));
  h_Dilep_TightMu_PFIsoBeta[0] = ((TH1F*) FindOutput("h_Dilep_TightMu_PFIsoBeta_Mu1"));
  h_Dilep_TightMu_PFIsoBeta[1] = ((TH1F*) FindOutput("h_Dilep_TightMu_PFIsoBeta_Mu2"));
  h_Dilep_TightMu_RelEff[0] = ((TH1F*) FindOutput("h_Dilep_TightMu_RelEff_Mu1"));
  h_Dilep_TightMu_RelEff[1] = ((TH1F*) FindOutput("h_Dilep_TightMu_RelEff_Mu2"));
  h_Dilep_Chi2[0] = ((TH1F*) FindOutput("h_Dilep_Chi2_Mu1"));
  h_Dilep_Chi2[1] = ((TH1F*) FindOutput("h_Dilep_Chi2_Mu2"));
  h_Dilep_StaHits[0] = ((TH1F*) FindOutput("h_Dilep_StaHits_Mu1"));
  h_Dilep_StaHits[1] = ((TH1F*) FindOutput("h_Dilep_StaHits_Mu2"));

  h_Dilep_StaHitsEta[0] = ((TH2F*) FindOutput("h_Dilep_StaHitsEta_Mu1"));
  h_Dilep_StaHitsEta[1] = ((TH2F*) FindOutput("h_Dilep_StaHitsEta_Mu2"));
  h_Dilep_StaHitsPV[0] = ((TH2F*) FindOutput("h_Dilep_StaHitsPV_Mu1"));
  h_Dilep_StaHitsPV[1] = ((TH2F*) FindOutput("h_Dilep_StaHitsPV_Mu2"));

  h_Dilep_StaNStation[0] = ((TH1F*) FindOutput("h_Dilep_StaNStation_Mu1"));
  h_Dilep_StaNStation[1] = ((TH1F*) FindOutput("h_Dilep_StaNStation_Mu2"));

  h_Dilep_StaNStationEta[0] = ((TH2F*) FindOutput("h_Dilep_StaNStationEta_Mu1"));
  h_Dilep_StaNStationEta[1] = ((TH2F*) FindOutput("h_Dilep_StaNStationEta_Mu2"));
  h_Dilep_StaNStationPV[0] = ((TH2F*) FindOutput("h_Dilep_StaNStationPV_Mu1"));
  h_Dilep_StaNStationPV[1] = ((TH2F*) FindOutput("h_Dilep_StaNStationPV_Mu2"));

  h_Dilep_PixelHits[0] = ((TH1F*) FindOutput("h_Dilep_PixelHits_Mu1"));
  h_Dilep_PixelHits[1] = ((TH1F*) FindOutput("h_Dilep_PixelHits_Mu2"));
  h_Dilep_TkLayers[0] = ((TH1F*) FindOutput("h_Dilep_TkLayers_Mu1"));
  h_Dilep_TkLayers[1] = ((TH1F*) FindOutput("h_Dilep_TkLayers_Mu2"));
  h_Dilep_dxy[0] = ((TH1F*) FindOutput(" h_Dilep_dxy_Mu1"));
  h_Dilep_dxy[1] = ((TH1F*) FindOutput(" h_Dilep_dxy_Mu2"));

  h_Dilep_dz_GTrack[0] = ((TH1F*) FindOutput(" h_Dilep_dz_GTrack_Mu1"));
  h_Dilep_dz_GTrack[1] = ((TH1F*) FindOutput(" h_Dilep_dz_GTrack_Mu2"));
  h_Dilep_dz_InTrack[0] = ((TH1F*) FindOutput(" h_Dilep_dz_InTrack_Mu1"));
  h_Dilep_dz_InTrack[1] = ((TH1F*) FindOutput(" h_Dilep_dz_InTrack_Mu2"));


  h_Dilep_dz[0] = ((TH1F*) FindOutput(" h_Dilep_dz_Mu1"));
  h_Dilep_dz[1] = ((TH1F*) FindOutput(" h_Dilep_dz_Mu2"));
  h_Dilep_dzMu[0] = ((TH1F*) FindOutput(" h_Dilep_dzMu_Mu1"));
  h_Dilep_dzMu[1] = ((TH1F*) FindOutput(" h_Dilep_dzMu_Mu2"));
  h_Dilep_dz_BestTrack[0] = ((TH1F*) FindOutput(" h_Dilep_dz_BestTrack_Mu1"));
  h_Dilep_dz_BestTrack[1] = ((TH1F*) FindOutput(" h_Dilep_dz_BestTrack_Mu2"));

  h_Dilep_dz_bf_dy[0] = ((TH1F*) FindOutput(" h_Dilep_dz_bf_dy_Mu1"));
  h_Dilep_dz_bf_dy[1] = ((TH1F*) FindOutput(" h_Dilep_dz_bf_dy_Mu2"));
  h_Dilep_dzMu_bf_dy[0] = ((TH1F*) FindOutput(" h_Dilep_dzMu_bf_dy_Mu1"));
  h_Dilep_dzMu_bf_dy[1] = ((TH1F*) FindOutput(" h_Dilep_dzMu_bf_dy_Mu2"));
  h_Dilep_dz_BestTrack_bf_dy[0] = ((TH1F*) FindOutput(" h_Dilep_dz_BestTrack_bf_dy_Mu1"));
  h_Dilep_dz_BestTrack_bf_dy[1] = ((TH1F*) FindOutput(" h_Dilep_dz_BestTrack_bf_dy_Mu2"));

  h_TrueDilep_dz[0] = ((TH1F*) FindOutput(" h_TrueDilep_dz_Mu1"));
  h_TrueDilep_dz[1] = ((TH1F*) FindOutput(" h_TrueDilep_dz_Mu2"));
  h_TrueDilep_dzMu[0] = ((TH1F*) FindOutput(" h_TrueDilep_dzMu_Mu1"));
  h_TrueDilep_dzMu[1] = ((TH1F*) FindOutput(" h_TrueDilep_dzMu_Mu2"));
  h_TrueDilep_dz_BestTrack[0] = ((TH1F*) FindOutput(" h_TrueDilep_dz_BestTrack_Mu1"));
  h_TrueDilep_dz_BestTrack[1] = ((TH1F*) FindOutput(" h_TrueDilep_dz_BestTrack_Mu2"));

  h_TrueDilep_dz_bf_dy[0] = ((TH1F*) FindOutput(" h_TrueDilep_dz_bf_dy_Mu1"));
  h_TrueDilep_dz_bf_dy[1] = ((TH1F*) FindOutput(" h_TrueDilep_dz_bf_dy_Mu2"));
  h_TrueDilep_dzMu_bf_dy[0] = ((TH1F*) FindOutput(" h_TrueDilep_dzMu_bf_dy_Mu1"));
  h_TrueDilep_dzMu_bf_dy[1] = ((TH1F*) FindOutput(" h_TrueDilep_dzMu_bf_dy_Mu2"));
  h_TrueDilep_dz_BestTrack_bf_dy[0] = ((TH1F*) FindOutput(" h_TrueDilep_dz_BestTrack_bf_dy_Mu1"));
  h_TrueDilep_dz_BestTrack_bf_dy[1] = ((TH1F*) FindOutput(" h_TrueDilep_dz_BestTrack_bf_dy_Mu2"));


  h_Dilep_dz_PV_Eq[0] = ((TH1F*) FindOutput(" h_Dilep_dz_PVSel_Equal_Mu1"));
  h_Dilep_dz_PV_Eq[1] = ((TH1F*) FindOutput(" h_Dilep_dz_PVSel_Equal_Mu2"));
  h_Dilep_dzMu_PV_Eq[0] = ((TH1F*) FindOutput(" h_Dilep_dzMu_PVSel_Equal_Mu1"));
  h_Dilep_dzMu_PV_Eq[1] = ((TH1F*) FindOutput(" h_Dilep_dzMu_PVSel_Equal_Mu2"));

  h_Dilep_dz_PV_NEq[0] = ((TH1F*) FindOutput(" h_Dilep_dz_PVSel_Not_Equal_Mu1"));
  h_Dilep_dz_PV_NEq[1] = ((TH1F*) FindOutput(" h_Dilep_dz_PVSel_Not_Equal_Mu2"));
  h_Dilep_dzMu_PV_NEq[0] = ((TH1F*) FindOutput(" h_Dilep_dzMu_PVSel_Not_Equal_Mu1"));
  h_Dilep_dzMu_PV_NEq[1] = ((TH1F*) FindOutput(" h_Dilep_dzMu_PVSel_Not_Equal_Mu2"));


  h_2D_Dilep_dz_Eff   =  ((TH1F*) FindOutput("h_2D_Dilep_dz_Eff"));
  h_2D_Dilep_dzMu_Eff =  ((TH1F*) FindOutput("h_2D_Dilep_dzMu_Eff"));
  h_2D_Dilep_dzBT_Eff =  ((TH1F*) FindOutput("h_2D_Dilep_dzBestTrack_Eff"));
  h_2D_Dilep_dz_bf_dy_Eff   =  ((TH1F*) FindOutput("h_2D_Dilep_dz_bf_dy_Eff"));
  h_2D_Dilep_dzMu_bf_dy_Eff =  ((TH1F*) FindOutput("h_2D_Dilep_dzMu_bf_dy_Eff"));
  h_2D_Dilep_dzBT_bf_dy_Eff =  ((TH1F*) FindOutput("h_2D_Dilep_dzBestTrack_bf_dy_Eff"));


  h_2D_Dilep_dz = ((TH2F*) FindOutput("h_2D_Dilep_dz"));
  h_2D_Dilep_dzMu = ((TH2F*) FindOutput("h_2D_Dilep_dzMu"));
  h_2D_Dilep_dzBT = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack"));

  h_2D_Dilep_dz_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dz_PVSel_Equal"));
  h_2D_Dilep_dzMu_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dzMu_PVSel_Equal"));
  h_2D_Dilep_dzBT_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack_PVSel_Equal"));

  h_2D_Dilep_dz_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dz_PVSel_Not_Equal"));
  h_2D_Dilep_dzMu_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dzMu_PVSel_Not_Equal"));
  h_2D_Dilep_dzBT_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack_PVSel_Not_Equal"));

  h_2D_Dilep_dz_bf_dy = ((TH2F*) FindOutput("h_2D_Dilep_dz_bf_dy"));
  h_2D_Dilep_dzMu_bf_dy = ((TH2F*) FindOutput("h_2D_Dilep_dzMu_bf_dy"));
  h_2D_Dilep_dzBT_bf_dy = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack_bf_dy"));

  h_2D_Dilep_dz_bf_dy_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dz_bf_dy_PVSel_Equal"));
  h_2D_Dilep_dzMu_bf_dy_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dzMu_bf_dy_PVSel_Equal"));
  h_2D_Dilep_dzBT_bf_dy_PV_Eq = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack_bf_dy_PVSel_Equal"));

  h_2D_Dilep_dz_bf_dy_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dz_bf_dy_PVSel_Not_Equal"));
  h_2D_Dilep_dzMu_bf_dy_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dzMu_bf_dy_PVSel_Not_Equal"));
  h_2D_Dilep_dzBT_bf_dy_PV_NEq = ((TH2F*) FindOutput("h_2D_Dilep_dzBestTrack_bf_dy_PVSel_Not_Equal"));


  h_Dilep_Gen_Muon_MpdgId = ((TH1F*) FindOutput("h_Dilep_Gen_Muon_MpdgId"));
  h_Dilep_Gen_Muon_MpdgId_PV_Eq = ((TH1F*) FindOutput("h_Dilep_Gen_Muon_MpdgId_PVSel_Equal"));
  h_Dilep_Gen_Muon_MpdgId_PV_NEq = ((TH1F*) FindOutput("h_Dilep_Gen_Muon_MpdgId_PVSel_Not_Equal"));

  h_Dilep_Jet_Energy = ((TH1F*) FindOutput("h_Dilep_Jet_Energy"));
  h_Dilep_Jet_Energy_PV_Eq = ((TH1F*) FindOutput("h_Dilep_Jet_Energy_PVSel_Equal"));
  h_Dilep_Jet_Energy_PV_NEq = ((TH1F*) FindOutput("h_Dilep_Jet_Energy_PVSel_Not_Equal"));
  
  h_Dilep_N_Jets = ((TH1F*) FindOutput("h_Dilep_N_Jets")); 
  h_Dilep_N_Jets_PV_Eq = ((TH1F*) FindOutput("h_Dilep_N_Jets_PVSel_Equal"));
  h_Dilep_N_Jets_PV_NEq = ((TH1F*) FindOutput("h_Dilep_N_Jets_PVSel_Not_Equal"));


  //------>  Plots after Tight Muon ID+ISO at dilepton level
  h_Dilep_TightMuISO_pt[0]=((TH1F*) FindOutput("h_Dilep_TightMuISO_pt_Mu1"));
  h_Dilep_TightMuISO_pt[1]=((TH1F*) FindOutput("h_Dilep_TightMuISO_pt_Mu2"));
  h_Dilep_TightMuISO_eta[0]=((TH1F*) FindOutput("h_Dilep_TightMuISO_eta_Mu1"));
  h_Dilep_TightMuISO_eta[1]=((TH1F*) FindOutput("h_Dilep_TightMuISO_eta_Mu2"));


  //------>  Plots after Tight Muon ID at WW level
  h_WWlevel_TightMu_pt[0] = ((TH1F*) FindOutput(" h_WWlevel_TightMu_pt_Mu1"));
  h_WWlevel_TightMu_pt[1] = ((TH1F*) FindOutput(" h_WWlevel_TightMu_pt_Mu2"));
  h_WWlevel_TightMu_eta[0] = ((TH1F*) FindOutput(" h_WWlevel_TightMu_eta_Mu1"));
  h_WWlevel_TightMu_eta[1] = ((TH1F*) FindOutput(" h_WWlevel_TightMu_eta_Mu2"));
  h_WWlevel_TightMu_PFIsoBeta[0] = ((TH1F*) FindOutput("h_WWlevel_TightMu_PFIsoBeta_Mu1"));
  h_WWlevel_TightMu_PFIsoBeta[1] = ((TH1F*) FindOutput("h_WWlevel_TightMu_PFIsoBeta_Mu2"));

  h_WWlevel_Chi2[0] = ((TH1F*) FindOutput("h_WWlevel_Chi2_Mu1"));
  h_WWlevel_Chi2[1] = ((TH1F*) FindOutput("h_WWlevel_Chi2_Mu2"));
  h_WWlevel_StaHits[0] = ((TH1F*) FindOutput("h_WWlevel_StaHits_Mu1"));
  h_WWlevel_StaHits[1] = ((TH1F*) FindOutput("h_WWlevel_StaHits_Mu2"));
  h_WWlevel_StaNStation[0] = ((TH1F*) FindOutput("h_WWlevel_StaNStation_Mu1"));
  h_WWlevel_StaNStation[1] = ((TH1F*) FindOutput("h_WWlevel_StaNStation_Mu2"));
  h_WWlevel_PixelHits[0] = ((TH1F*) FindOutput("h_WWlevel_PixelHits_Mu1"));
  h_WWlevel_PixelHits[1] = ((TH1F*) FindOutput("h_WWlevel_PixelHits_Mu2"));
  h_WWlevel_TkLayers[0] = ((TH1F*) FindOutput("h_WWlevel_TkLayers_Mu1"));
  h_WWlevel_TkLayers[1] = ((TH1F*) FindOutput("h_WWlevel_TkLayers_Mu2"));
  h_WWlevel_dxy [0] = ((TH1F*) FindOutput(" h_WWlevel_dxy_Mu1"));
  h_WWlevel_dxy [1] = ((TH1F*) FindOutput(" h_WWlevel_dxy_Mu2"));
  h_WWlevel_dz [0] = ((TH1F*) FindOutput(" h_WWlevel_dz_Mu1"));
  h_WWlevel_dz [1] = ((TH1F*) FindOutput(" h_WWlevel_dz_Mu2"));


 //------>  Plots after Tight Muon ID+ISO at WW level
  h_WWlevel_TightMuISO_pt[0]=((TH1F*) FindOutput("h_WWlevel_TightMuISO_pt_Mu1"));
  h_WWlevel_TightMuISO_pt[1]=((TH1F*) FindOutput("h_WWlevel_TightMuISO_pt_Mu2"));
  h_WWlevel_TightMuISO_eta[0]=((TH1F*) FindOutput("h_WWlevel_TightMuISO_eta_Mu1"));
  h_WWlevel_TightMuISO_eta[1]=((TH1F*) FindOutput("h_WWlevel_TightMuISO_eta_Mu2"));


}


void muonAnalyzer::Summary() {

  cout << " ---------------------------------------------------" << endl;
  cout << " " << endl;
  
  InitialiseParameters();

  cout << " Number of Events::  " << NEvents  << endl;

  double factN = 1.; 
  if (XSection > 0) factN = XSection * Luminosity / NEvents; //fractionoftotalevents;


  cout << " Normalization factor: " << factN << endl;
  cout << endl;
  cout << " ---------------------------------------------------" << endl;

}
