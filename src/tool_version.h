#ifndef HEADER_CURL_TOOL_VERSION_H
#define HEADER_CURL_TOOL_VERSION_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/
#include <curl/curlver.h>

#define CURL_STR(X) #X
#define CURL_STR2(X) CURL_STR(X)

#ifndef CURL_CUSTOM_NAME
#define CURL_NAME "curl"
#else
#define CURL_NAME CURL_STR2(CURL_CUSTOM_NAME)
#endif

#define CURL_COPYRIGHT LIBCURL_COPYRIGHT

#ifndef CURL_VERSION
#define CURL_VERSION LIBCURL_VERSION
#endif

#define CURL_VERSION_MAJOR LIBCURL_VERSION_MAJOR
#define CURL_VERSION_MINOR LIBCURL_VERSION_MINOR
#define CURL_VERSION_PATCH LIBCURL_VERSION_PATCH

#ifdef CURL_COMMIT_ID
#define CURL_ID CURL_NAME " " CURL_VERSION "-" CURL_STR2(CURL_COMMIT_ID) " (" OS ") "
#else
#define CURL_ID CURL_NAME " " CURL_VERSION " (" OS ") "
#endif

#endif /* HEADER_CURL_TOOL_VERSION_H */
