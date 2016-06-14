import FWCore.ParameterSet.Config as cms

randomRecoTrackRefSelector = cms.EDProducer("RandomRecoTrackRefSelector",
    src = cms.InputTag("generalTracks"),
)
