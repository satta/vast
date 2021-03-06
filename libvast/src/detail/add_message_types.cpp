/******************************************************************************
 *                    _   _____   __________                                  *
 *                   | | / / _ | / __/_  __/     Visibility                   *
 *                   | |/ / __ |_\ \  / /          Across                     *
 *                   |___/_/ |_/___/ /_/       Space and Time                 *
 *                                                                            *
 * This file is part of VAST. It is subject to the license terms in the       *
 * LICENSE file found in the top-level directory of this distribution and at  *
 * http://vast.io/license. No part of VAST, including this file, may be       *
 * copied, modified, propagated, or distributed except according to the terms *
 * contained in the LICENSE file.                                             *
 ******************************************************************************/

#include "vast/detail/add_message_types.hpp"

#include "vast/address.hpp"
#include "vast/atoms.hpp"
#include "vast/bitmap.hpp"
#include "vast/chunk.hpp"
#include "vast/command.hpp"
#include "vast/config.hpp"
#include "vast/detail/stable_map.hpp"
#include "vast/expression.hpp"
#include "vast/operator.hpp"
#include "vast/path.hpp"
#include "vast/pattern.hpp"
#include "vast/plugin.hpp"
#include "vast/port.hpp"
#include "vast/qualified_record_field.hpp"
#include "vast/query_options.hpp"
#include "vast/schema.hpp"
#include "vast/subnet.hpp"
#include "vast/system/actors.hpp"
#include "vast/system/component_registry.hpp"
#include "vast/system/query_status.hpp"
#include "vast/system/report.hpp"
#include "vast/system/type_registry.hpp"
#include "vast/table_slice.hpp"
#include "vast/table_slice_column.hpp"
#include "vast/taxonomies.hpp"
#include "vast/type.hpp"
#include "vast/uuid.hpp"

#include <caf/actor_system_config.hpp>
#include <caf/stream.hpp>
#include <caf/stream_slot.hpp>
#include <caf/typed_event_based_actor.hpp>

#include <utility>
#include <vector>

namespace vast::detail {

void add_message_types(caf::actor_system_config& cfg) {
  cfg.add_message_types<caf::id_block::vast_types>();
  cfg.add_message_types<caf::id_block::vast_atoms>();
  cfg.add_message_types<caf::id_block::vast_actors>();
}

} // namespace vast::detail
