////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/////            Muon Studies for CSA14                     ////

/////        A. Calderón (IFCA)   18 / 08 / 2014            ////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////





#ifndef MUONFR_NEWJETETDEF_H
#define MUONFR_NEWJETETDEF_H 1

#include "PAFAnalysis.h"

#include <TH1F.h>
#include <TMatrix.h>
#include <TH2F.h>
#include "TCounterUI.h"
#include <TLorentzVector.h>
#include "Riostream.h"  
#include "PUWeight.h"


class muonAnalyzer: public PAFAnalysis{

 public:
   muonAnalyzer(TTree *tree=0);
   virtual ~muonAnalyzer() {}

 protected:
   virtual void              Initialise();
   virtual void              InsideLoop();
   virtual void              SetDataMembersAtTermination();
   virtual void              Summary(); 
   void                      GetAllHWWMuons();
   void                      GetAllTightMuons();
   bool                      passPFIso (int);
   bool                      passTightMuCuts(int, 
					     float, 
					     float, 
					     float, 
					     int, 
					     int);
   void                      FillRelEff(string, int, int,double);
   void                      GetAllJets();
   Double_t                  giveMT(int, double, double);
   Double_t                  getDeltaR (int , int );
   Int_t                     SelectedVertexIndex();
   Int_t                     SelectedVertexIndex(int, int, double);
   float                     DeltaPhi(float, float);
   float                     projectedMET(int, int);
   float                     deltaPhiJet(int, int);
   float                     ptDilepton(int, int);
   bool                      passesAntiBTagging(int, int);    
   bool                      passesWWSelection(int, int, int);

  
 public:
 
   // My Declarations:
   // Define global variables

   PUWeight* fPUWeight;
 
   ///** GEN INFORMATION
   std::vector<TLorentzVector> G_GEN_PromptMuon_4vec;
   std::vector<TLorentzVector> G_GEN_PromptTauMuon_4vec;

   //** MUONS
   std::vector<TLorentzVector> G_Muon_4vec;
   std::vector<bool>           G_Muon_HWW_ID;
   std::vector<bool>           G_Muon_HWW_ISO;
   std::vector<bool>           G_Muon_TightID;
   std::vector<bool>           G_Muon_TightISO;
   std::vector<double>         G_Muon_PFIsoBeta;
   std::vector<bool>           G_Muon_MatchW;

   std::vector<bool>           G_Muon_Match_LeadJet;
   std::vector<bool>           G_Muon_Numerator;
   std::vector<bool>           G_Muon_Denominator;
   std::vector<double>         G_Muon_RelCombIsol;
   std::vector<double>         G_Muon_JetEt;
   std::vector<double>         G_Muon_JetEta;
   std::vector<bool>           G_Muon_match_jet;
   std::vector<double>         G_Muon_isoMVA;
  
   std::vector<double>         G_Muon_ChargeHPFRelISo;
   std::vector<double>         G_Muon_PFRelISo;
   std::vector<double>         G_Muon_PFChargedH;
   std::vector<double>         G_Muon_PFNeutralH;
   std::vector<double>         G_Muon_PFPhoton;
   std::vector<double>         G_Muon_PFRho;


   //** JETS 
   std::vector<TLorentzVector> G_Jet_4vec;   
   int         G_N_Jets;
   


   bool G_Debug_DefineAnalysisVariables;

 
   //* Histograms 

   TH1F       *h_N_dR_Vtx_Muon[2];
   TH1F       *h_N_dZ_PV0_PVLep;

   TH1F       *h_N_PV;
   TH1F       *h_N_Dilep_TypeMu;
   TH1F       *h_N_Dilep_TypeMu_LP;
   TH1F       *h_N_Dilep_TypeMu_HP;
   TH1F       *h_N_WWlevel_TypeMu;
   TH1F       *h_N_WWlevel_TypeMu_LP; 
   TH1F       *h_N_WWlevel_TypeMu_HP;
   TH1F       *h_N_Dilep_TigtMuCuts;
   TH1F       *h_N_WWlevel_TigtMuCuts;
  
   TH1F       *h_N_Dilep_TightMuCuts_butTkLayers [2]; 
   TH1F       *h_N_Dilep_TightMuCuts_butSTAHits [2];
   TH1F       *h_N_WWlevel_TightMuCuts_butTkLayers [2]; 
   TH1F       *h_N_WWlevel_TightMuCuts_butSTAHits [2];

   TH1F       *h_N_Dilep_GLBPF_butTkLayers [2]; 
   TH1F       *h_N_Dilep_GLBPF_butSTAHits [2];
   TH1F       *h_N_WWlevel_GLBPF_butTkLayers [2]; 
   TH1F       *h_N_WWlevel_GLBPF_butSTAHits [2];

   TH1F       *h_Dilep_AllMu_PFIsoBeta_Mu1;
   TH1F       *h_Dilep_AllMu_PFIsoBeta_Mu2;
   TH1F       *h_Dilep_HWWMu_PFIsoBeta_Mu1;
   TH1F       *h_Dilep_HWWMu_PFIsoBeta_Mu2; 
   TH1F       *h_WWlevel_HWWMu_PFIsoBeta_Mu1;
   TH1F       *h_WWlevel_HWWMu_PFIsoBeta_Mu2;


   //------>  Plots after Tight Muon ID at dilepton level
   TH1F       *h_Dilep_TightMuon_TkLayers [2];
   TH1F       *h_Dilep_TightMuon_StaHits [2];
   TH1F       *h_Dilep_TightMu_PFCH [2];
   TH1F       *h_Dilep_TightMu_PFNH [2]; 
   TH1F       *h_Dilep_TightMu_PFPh [2]; 
   TH1F       *h_Dilep_TightMu_PFRho [2];

   TH1F       *h_Dilep_TightMu_pt [2];
   TH1F       *h_Dilep_TightMu_eta [2];
   TH1F       *h_Dilep_TightMu_PFIsoBeta [2];
   TH1F       *h_Dilep_TightMu_RelEff [2];
   TH1F       *h_Dilep_Chi2 [2];
   TH1F       *h_Dilep_StaHits [2];
   TH2F       *h_Dilep_StaHitsEta [2];
   TH2F       *h_Dilep_StaHitsPV [2];
   TH1F       *h_Dilep_StaNStation [2];
   TH2F       *h_Dilep_StaNStationEta [2];
   TH2F       *h_Dilep_StaNStationPV [2];
   TH1F       *h_Dilep_PixelHits [2]; 
   TH1F       *h_Dilep_TkLayers [2]; 
   TH1F       *h_Dilep_dxy [2];
   TH1F       *h_Dilep_dz [2];
   TH1F       *h_Dilep_dzMu [2];

   //------>  Plots after Tight Muon ID+ISO at dilepton level
   TH1F       *h_Dilep_TightMuISO_pt  [2];
   TH1F       *h_Dilep_TightMuISO_eta [2];

   //------>  Plots after Tight Muon ID at WW level 
   TH1F       *h_WWlevel_TightMu_pt [2];
   TH1F       *h_WWlevel_TightMu_eta [2];
   TH1F       *h_WWlevel_TightMu_PFIsoBeta [2];
   TH1F       *h_WWlevel_Chi2 [2];
   TH1F       *h_WWlevel_StaHits [2];
   TH1F       *h_WWlevel_StaNStation [2];
   TH1F       *h_WWlevel_PixelHits [2]; 
   TH1F       *h_WWlevel_TkLayers [2]; 
   TH1F       *h_WWlevel_dxy [2];
   TH1F       *h_WWlevel_dz [2];

   //------>  Plots after Tight Muon ID+ISO at dilepton level
   TH1F       *h_WWlevel_TightMuISO_pt  [2];
   TH1F       *h_WWlevel_TightMuISO_eta [2];


   // * Input parameters
   TString  Signal;       // Type of Signal
   int      NEvents;      // Total number of events in the sample before skim
   double   Luminosity;   // Total luminosity
   double   XSection;     // Process cross section
   bool     IsDATA; // True if is Data, False in case MC
   int      WhichRun; // 1 in case of RunI samples. 2 In case of RunII samples.;

   ClassDef(muonAnalyzer,0);
};
#endif

