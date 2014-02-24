/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.26 2005/04/26 22:13:28 rstory Exp $
 *
 * $Id:$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef RADIUSAUTHSERVEREXTTABLE_H
#define RADIUSAUTHSERVEREXTTABLE_H

#include "tr069_token.h"
#include "tr069_store.h"

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

/** Index radiusAuthServerExtIndex is internal */

typedef struct radiusAuthServerExtTable_context_s {
	netsnmp_index   index;                         /** THIS MUST BE FIRST!!! */
	
	long            radiusAuthServerExtIndex;      /** INTEGER32 = ASN_INTEGER */
	unsigned long   radiusAuthClientCounterDiscontinuity;
	oid             oid[1];
	
	struct tr069_value_table *client;
} radiusAuthServerExtTable_context;

#define radiusAuthServerExtTable_TABLE_OID 1,3,6,1,2,1,67,1,2,1,1,4

/*************************************************************
 * column number definitions for table radiusAuthServerExtTable
 */
#define COLUMN_RADIUSAUTHSERVEREXTINDEX 1
#define COLUMN_RADIUSAUTHSERVERINETADDRESSTYPE 2
#define COLUMN_RADIUSAUTHSERVERINETADDRESS 3
#define COLUMN_RADIUSAUTHCLIENTSERVERINETPORTNUMBER 4
#define COLUMN_RADIUSAUTHCLIENTEXTROUNDTRIPTIME 5
#define COLUMN_RADIUSAUTHCLIENTEXTACCESSREQUESTS 6
#define COLUMN_RADIUSAUTHCLIENTEXTACCESSRETRANSMISSIONS 7
#define COLUMN_RADIUSAUTHCLIENTEXTACCESSACCEPTS 8
#define COLUMN_RADIUSAUTHCLIENTEXTACCESSREJECTS 9
#define COLUMN_RADIUSAUTHCLIENTEXTACCESSCHALLENGES 10
#define COLUMN_RADIUSAUTHCLIENTEXTMALFORMEDACCESSRESPONSES 11
#define COLUMN_RADIUSAUTHCLIENTEXTBADAUTHENTICATORS 12
#define COLUMN_RADIUSAUTHCLIENTEXTPENDINGREQUESTS 13
#define COLUMN_RADIUSAUTHCLIENTEXTTIMEOUTS 14
#define COLUMN_RADIUSAUTHCLIENTEXTUNKNOWNTYPES 15
#define COLUMN_RADIUSAUTHCLIENTEXTPACKETSDROPPED 16
#define COLUMN_RADIUSAUTHCLIENTCOUNTERDISCONTINUITY 17
#define radiusAuthServerExtTable_COL_MIN 2
#define radiusAuthServerExtTable_COL_MAX 17

void init_radiusAuthServerExtTable(void);
void add_radiusAuthServerExtTable(tr069_id id, struct tr069_value_table *client);
void del_radiusAuthServerExtTable(tr069_id id);

#endif /** RADIUSAUTHSERVEREXTTABLE_H */