/** \class reco::RandomRecoTrackRefSelector
 *
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/UtilAlgos/interface/ObjectSelectorStreamProducer.h"
//#include "CommonTools/RecoAlgos/interface/TrackSelector.h"
#include "CommonTools/RecoAlgos/interface/RandomRecoTrackRefSelector.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

namespace reco {
  typedef ObjectSelectorStreamProducer<RandomRecoTrackRefSelector,reco::TrackRefVector> RandomRecoTrackRefSelector;
  DEFINE_FWK_MODULE(RandomRecoTrackRefSelector);
}

/*
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/RecoAlgos/interface/TrackSelector.h"
#include "CommonTools/RecoAlgos/interface/TrackFullCloneSelectorBase.h"
//#include "CommonTools/RecoAlgos/interface/RecoTrackSelector.h"
#include "CommonTools/RecoAlgos/interface/RandomRecoTrackRefSelector.h"

namespace reco {
  namespace modules {
      //typedef ObjectSelector<RecoTrackSelector> RecoTrackSelector;
      //typedef ObjectSelector<RandomRecoTrackRefSelector,std::vector<const reco::Track*>> RandomRecoTrackRefSelector;
      //typedef ObjectSelectorStreamProducer<RandomRecoTrackRefSelector,std::vector<const reco::Track*>> RandomRecoTrackRefSelector;
      //typedef TrackFullCloneSelectorBase<RecoTrackSelector> RecoTrackSelector;
      typedef TrackFullCloneSelectorBase<RandomRecoTrackRefSelector> RandomRecoTrackRefSelector;
      DEFINE_FWK_MODULE(RandomRecoTrackRefSelector);
  }
}
*/
