/*
 * Copyright (C) 1994-2018 Altair Engineering, Inc.
 * For more information, contact Altair at www.altair.com.
 *
 * This file is part of the PBS Professional ("PBS Pro") software.
 *
 * Open Source License Information:
 *
 * PBS Pro is free software. You can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * PBS Pro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Commercial License Information:
 *
 * For a copy of the commercial license terms and conditions,
 * go to: (http://www.pbspro.com/UserArea/agreement.html)
 * or contact the Altair Legal Department.
 *
 * Altair’s dual-license business model allows companies, individuals, and
 * organizations to create proprietary derivative works of PBS Pro and
 * distribute them - whether embedded or bundled with other software -
 * under a commercial license agreement.
 *
 * Use of Altair’s trademarks, including but not limited to "PBS™",
 * "PBS Professional®", and "PBS Pro™" and Altair’s logos is subject to Altair's
 * trademark licensing policies.
 *
 */
/**
 * @file	enc_UserCred.c
 */

#include <pbs_config.h>   /* the master config generated by configure */

#include "libpbs.h"
#include "pbs_error.h"
#include "dis.h"

/**
 * @brief
 *	- encode a User Credential Batch Request
 *
 * @param[in] sock - socket descriptor
 * @param[in] user - user name
 * @param[in] type -  Credential type
 * @param[in] cred- the credential
 * @param[in] len - length of credential
 *
 * @return      int
 * @retval      DIS_SUCCESS(0)  success
 * @retval      error code      error
 *
 */

int
encode_DIS_UserCred(int sock, char *user, int type, char *cred, int len)
{
	int   rc;


	if ((rc = diswst(sock, user)) != 0)
		return rc;
	if ((rc = diswui(sock, type)) != 0)
		return rc;
	rc = diswcs(sock, cred, (size_t)len);

	return rc;
}

/**
 * @brief
 * 	- encode a User Migrate Batch Request
 *
 * @param[in] sock - socket descriptor
 * @param[in] tohost - the destination host to migrate users to
 *
 * @return      int
 * @retval      DIS_SUCCESS(0)  success
 * @retval      error code      error
 *
 */

int
encode_DIS_UserMigrate(int sock, char *tohost)
{
	int   rc;


	rc = diswst(sock, tohost);

	return rc;
}
