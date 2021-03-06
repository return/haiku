/*
 * Copyright 2017, Andrew Lindesay <apl@lindesay.co.nz>.
 * All rights reserved. Distributed under the terms of the MIT License.
 */

#ifndef SERVER_SETTINGS_H
#define SERVER_SETTINGS_H

#include <File.h>
#include <HttpHeaders.h>
#include <String.h>
#include <Url.h>


class ServerSettings {
public:
		static status_t					SetBaseUrl(const BUrl& baseUrl);
		static const BString			GetUserAgent();
		static void						AugmentHeaders(BHttpHeaders& headers);
		static BUrl						CreateFullUrl(
											const BString urlPathComponents);

		static bool						PreferCache();
		static void						SetPreferCache(bool value);
		static bool						DropCache();
		static void						SetDropCache(bool value);
		static bool						ForceNoNetwork();
		static void						SetForceNoNetwork(bool value);

private:
		static void						_InitUserAgent();
		static const BString			_GetUserAgentVersionString();

		static BUrl						sBaseUrl;
		static BString					sUserAgent;
		static pthread_once_t			sUserAgentInitOnce;
		static bool						sPreferCache;
		static bool						sDropCache;
		static bool						sForceNoNetwork;
};

#endif // SERVER_SETTINGS_H
