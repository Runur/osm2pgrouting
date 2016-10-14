/***************************************************************************
 *   Copyright (C) 2008 by Daniel Wendt                                    *
 *   gentoo.murray@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SRC_OSMDOCUMENT_H_
#define SRC_OSMDOCUMENT_H_

#include <map>
#include <vector>
#include "./Configuration.h"

namespace osm2pgr {


class Node;
class Way;
class Relation;

/**
    An osm-document.
*/
class OSMDocument {
 public:
    //! Constructor
    explicit OSMDocument(Configuration& config, size_t lines);

    //! Destructor
    virtual ~OSMDocument();

    //! add node to the map
    void AddNode(Node n);

    //! add way to the map
    void AddWay(Way w);

    //! find node by using an ID
    bool has_node(int64_t nodeRefId) const;
    Node* FindNode(int64_t nodeRefId);

    bool has_way(int64_t way_id) const;
    Way* FindWay(int64_t way_id);

    void AddRelation(Relation* r);

 public:
    // ! parsed nodes
    std::map<int64_t, Node> m_Nodes;
    //! parsed ways
    std::map<int64_t, Way> m_Ways;
    //! parsed relations
    std::vector<Relation*> m_Relations;


    Configuration& m_rConfig;
    size_t m_lines;
};

}  // end namespace osm2pgr
#endif  // SRC_OSMDOCUMENT_H_
