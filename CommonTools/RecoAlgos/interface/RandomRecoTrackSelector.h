#ifndef RecoSelectors_RandomRecoTrackSelector_h
#define RecoSelectors_RandomRecoTrackSelector_h
/* \class RecoTrackSelector
 *
 * \author Giuseppe Cerati, INFN
 *
 */
#include "CommonTools/RecoAlgos/interface/RecoTrackSelectorBase.h"
#include <cstdlib>

class RandomRecoTrackSelector : public RecoTrackSelectorBase {
 public:
  typedef reco::TrackCollection collection;
  typedef std::vector<const reco::Track *> container;
  typedef container::const_iterator const_iterator;

  /// Constructors
  RandomRecoTrackSelector() {}
  RandomRecoTrackSelector ( const edm::ParameterSet & cfg, edm::ConsumesCollector && iC ) : RecoTrackSelectorBase( cfg, iC ) {}

  const_iterator begin() const { return selected_.begin(); }
  const_iterator end() const { return selected_.end(); }

  void select( const edm::Handle<collection>& c, const edm::Event & event, const edm::EventSetup&es) {
    init(event,es);
    selected_.clear();
    for( reco::TrackCollection::const_iterator trk = c->begin();trk != c->end(); ++ trk ){
      if ( operator()(*trk) ) {
        double r = ((double) rand() / (RAND_MAX));
        if(r < 1)
	        selected_.push_back( & * trk );
      }
    }
  }

  size_t size() const { return selected_.size(); }

 private:
  container selected_;
};

#endif
