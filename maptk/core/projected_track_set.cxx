/*ckwg +5
 * Copyright 2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

/**
 * \file
 * \brief projected_track_set implementation
 */

#include "projected_track_set.h"

#include <boost/foreach.hpp>

namespace maptk
{


/// Use the cameras to project the landmarks back into their images.
track_set_sptr
projected_tracks(landmark_map_sptr landmarks, camera_map_sptr cameras)
{
  std::vector<track_sptr> tracks;

  camera_map::map_camera_t cam_map = cameras->cameras();
  landmark_map::map_landmark_t lm_map = landmarks->landmarks();

  for( landmark_map::map_landmark_t::iterator l = lm_map.begin(); l != lm_map.end(); l++ )
  {
    track_sptr t( new track );
    t->set_id( l->first );
    tracks.push_back( t );

    BOOST_FOREACH( const camera_map::map_camera_t::value_type& p, cam_map )
    {
      const camera_d& cam = dynamic_cast<const camera_d&>( *p.second );
      feature_sptr f( new feature_d( cam.project( l->second->loc() ) ) );
      t->append( track::track_state( p.first, f, descriptor_sptr() ) );
    }
  }
  return track_set_sptr( new simple_track_set( tracks ) );
}


} // end namespace maptk