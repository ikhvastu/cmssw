import FWCore.ParameterSet.Config as cms

from CommonTools.RecoAlgos.recoTrackSelectorPSet_cfi import recoTrackSelectorPSet as _recoTrackSelectorPSet

randomRecoTrackSelector = cms.EDFilter("RandomRecoTrackSelector",
    #src = cms.InputTag("generalTracks"),
    _recoTrackSelectorPSet
)
