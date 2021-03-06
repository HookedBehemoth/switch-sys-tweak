/*
 * Copyright (c) 2018 p-sam
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "nsvm_mitm_service.hpp"
#include "file_utils.hpp"

bool NsVmMitmService::ShouldMitm(const ams::sm::MitmProcessInfo& client_info) {
	bool should_mitm = (
		client_info.program_id == ams::ncm::SystemAppletId::WifiWebAuth ||
		client_info.program_id == ams::ncm::SystemAppletId::Web ||
		client_info.program_id == ams::ncm::SystemAppletId::OfflineWeb
	);

	FILE_LOG_IPC(NSVM_MITM_SERVICE_NAME, client_info, "() // %s", should_mitm ? "true" : "false");
	return should_mitm;
}

ams::Result NsVmMitmService::NeedsUpdateVulnerability(ams::sf::Out<u8> out) {
	out.SetValue(0);
	FILE_LOG_IPC_CLASS("() // %x", out.GetValue());
	return ams::ResultSuccess();
}
