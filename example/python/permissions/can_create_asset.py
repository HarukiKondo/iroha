#
# Copyright Soramitsu Co., Ltd. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0
#

import irohalib
import commons
import primitive_pb2

admin = commons.new_user('admin@test')
alice = commons.new_user('alice@test')
iroha = irohalib.Iroha(admin['id'])


@commons.hex
def genesis_tx():
    test_permissions = [primitive_pb2.can_create_asset]
    genesis_commands = commons.genesis_block(admin, alice, test_permissions)
    tx = iroha.transaction(genesis_commands)
    irohalib.IrohaCrypto.sign_transaction(tx, admin['key'])
    return tx


@commons.hex
def create_asset_tx():
    tx = iroha.transaction([
        iroha.command('CreateAsset', asset_name='coin', domain_id='test', precision=2)
    ], creator_account=alice['id'])
    irohalib.IrohaCrypto.sign_transaction(tx, alice['key'])
    return tx
