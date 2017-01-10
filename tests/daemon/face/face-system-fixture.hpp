/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2017,  Regents of the University of California,
 *                           Arizona Board of Regents,
 *                           Colorado State University,
 *                           University Pierre & Marie Curie, Sorbonne University,
 *                           Washington University in St. Louis,
 *                           Beijing Institute of Technology,
 *                           The University of Memphis.
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NFD_TESTS_DAEMON_FACE_FACE_SYSTEM_FIXTURE_HPP
#define NFD_TESTS_DAEMON_FACE_FACE_SYSTEM_FIXTURE_HPP

#include "face/face.hpp"
#include "face/face-system.hpp"
#include "fw/face-table.hpp"

#include "tests/test-common.hpp"

namespace nfd {
namespace face {
namespace tests {

using namespace nfd::tests;

class FaceSystemFixture : public virtual BaseFixture
{
public:
  FaceSystemFixture()
    : faceSystem(faceTable)
  {
    faceSystem.setConfigFile(configFile);
  }

  void
  parseConfig(const std::string& text, bool isDryRun)
  {
    configFile.parse(text, isDryRun, "test-config");
  }

  /** \brief get ProtocolFactory from FaceSystem
   *  \tparam F ProtocolFactory subclass
   *
   *  If ProtocolFactory with \p scheme does not exist or has an incompatible type,
   *  this fails the test case.
   */
  template<typename F>
  F&
  getFactoryById(const std::string& id)
  {
    F* factory = dynamic_cast<F*>(faceSystem.getFactoryById(id));
    BOOST_REQUIRE(factory != nullptr);
    return *factory;
  }

  /** \brief get ProtocolFactory from FaceSystem
   *  \tparam F ProtocolFactory subclass
   *
   *  If ProtocolFactory with \p scheme does not exist or has an incompatible type,
   *  this fails the test case.
   */
  template<typename F>
  F&
  getFactoryByScheme(const std::string& scheme)
  {
    F* factory = dynamic_cast<F*>(faceSystem.getFactoryByScheme(scheme));
    BOOST_REQUIRE(factory != nullptr);
    return *factory;
  }

  /** \brief list faces of specified scheme from FaceTable
   *  \param scheme local or remote FaceUri scheme
   *  \param linkType if not NONE, filter by specified LinkType
   */
  std::vector<const Face*>
  listFacesByScheme(const std::string& scheme,
                    ndn::nfd::LinkType linkType = ndn::nfd::LINK_TYPE_NONE) const
  {
    std::vector<const Face*> faces;
    for (const Face& face : faceTable) {
      if ((face.getLocalUri().getScheme() == scheme ||
           face.getRemoteUri().getScheme() == scheme) &&
          (linkType == ndn::nfd::LINK_TYPE_NONE ||
           face.getLinkType() == linkType)) {
        faces.push_back(&face);
      }
    }
    return faces;
  }

protected:
  ConfigFile configFile;
  FaceTable faceTable;
  FaceSystem faceSystem;
};

} // namespace tests
} // namespace face
} // namespace nfd

#endif // NFD_TESTS_DAEMON_FACE_FACE_SYSTEM_FIXTURE_HPP
