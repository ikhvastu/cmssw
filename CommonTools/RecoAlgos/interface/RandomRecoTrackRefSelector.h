#ifndef RecoSelectors_RandomRecoTrackRefSelector_h
#define RecoSelectors_RandomRecoTrackRefSelector_h
/* \class RandomRecoTrackRefSelector
 *
 * \author Ian Tomalin, RAL
 * edited by Illia Khvastunov 13 Jun, 2016
 */
//#include "CommonTools/RecoAlgos/interface/RecoTrackSelectorBase.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include <cstdlib>

class RandomRecoTrackRefSelector {//: public RecoTrackSelectorBase {
 public:
  typedef reco::TrackCollection collection;
  typedef reco::TrackRefVector container;
  typedef container::const_iterator const_iterator;

  /// Constructors
  RandomRecoTrackRefSelector() {}

  //RandomRecoTrackRefSelector ( const edm::ParameterSet & cfg, edm::ConsumesCollector && iC ) : RecoTrackSelectorBase(cfg, iC) {}
  RandomRecoTrackRefSelector ( const edm::ParameterSet & cfg, edm::ConsumesCollector && iC ) {}

  const_iterator begin() const { return selected_.begin(); }
  const_iterator end() const { return selected_.end(); }

  void select( const edm::Handle<collection>& c, const edm::Event & event, const edm::EventSetup&es) {
    //init(event, es);
    selected_.clear();
    for (unsigned int i = 0; i < c->size(); i++) {
      edm::Ref<collection> trk(c, i);
      //if ( operator()(*trk) ) {
        double r = ((double) rand() / (RAND_MAX));
        if(r < 0.9)
	        selected_.push_back( trk );
      //}
    }
  }
  /*
  void select( const edm::Handle<collection>& c, const edm::Event & event, const edm::EventSetup&es) {
    //init(event,es);
    selected_.clear();
    for( reco::TrackCollection::const_iterator trk = c->begin();trk != c->end(); ++ trk ){
        double r = ((double) rand() / (RAND_MAX));
        if(r < 0.9)
           selected_.push_back( * trk );
    }
  }
  */

  size_t size() const { return selected_.size(); }

 private:
  container selected_;
};

#endif
