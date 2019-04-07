/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_MOCK_ON_DEMAND_OS_NOTIFICATION_OS_SIDE_HPP
#define IROHA_MOCK_ON_DEMAND_OS_NOTIFICATION_OS_SIDE_HPP

#include "ordering/on_demand_os_transport.hpp"

#include <gmock/gmock.h>

namespace iroha {
  namespace ordering {
    namespace transport {

      struct MockOdOsNotificationOsSide : public OdNotificationOsSide {
        MOCK_METHOD2(onBatches, void(CollectionType, InitiatorPeerType));

        MOCK_METHOD2(onRequestProposal,
                     boost::optional<std::shared_ptr<const ProposalType>>(
                         consensus::Round, InitiatorPeerType));
      };

    }  // namespace transport
  }    // namespace ordering
}  // namespace iroha

#endif  // IROHA_MOCK_ON_DEMAND_OS_NOTIFICATION_OS_SIDE_HPP