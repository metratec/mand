# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

AM_CFLAGS = -g -Werror -funit-at-a-time \
	-I$(top_srcdir) \
	-I$(top_srcdir)/include/compat \
	-I$(top_builddir)

SUBDIRS = snmp tests

sbin_PROGRAMS = dmctrl mand

noinst_LTLIBRARIES = libdm.la libdmstore.la
#noinst_BIN = dm_store

dmctrl_SOURCES = dmctrl.c
dmctrl_LDADD = $(top_builddir)/utils/libdmutils.la \
	       $(top_builddir)/libdmconfig/libdmconfig.la \
	       $(top_builddir)/libdmconfig/libdm_dmclient.la

libdmstore_la_SOURCES = dm_store.c dm_index.c dm_notify.c dm_cache.c \
			dm_serialize.c dm_deserialize.c dm_signature.c \
			dm_strings.c dm_action.c \
			dm_cfgversion.c \
			dm_cfg_bkrst.c dm_validate.c \
			p_table.c dm_assert.c
libdmstore_la_LIBADD = $(LIBM) $(DMLIBS) $(top_builddir)/utils/libdmutils.la

libdm_la_SOURCES = \
		dm_dmconfig.c \
		process.c \
		inet_helper.c \
		dm_luaif.c

BUILT_SOURCES = p_table.c p_table.h dm_action_table.c dm_action_table.h
CLEANFILES = p_table.c p_table.h

DISTCLEANFILES = *xml *.log *~

libdm_la_LIBADD = $(LIBM) $(DMLIBS) $(NVRAMLIBS) \
			libdmstore.la \
			$(top_builddir)/utils/libdmutils.la \
			$(top_builddir)/libdmconfig/libdmconfig.la

mand_SOURCES = mand.c dm.c \
		 dm_action_table.c

if AGENTX
libdm_la_LIBADD += snmp/libsnmp.la
endif

if NET_SNMP
mand_SOURCES += net-snmpd.c
endif

mand_LDADD = libdm.la $(top_builddir)/libdmconfig/libdm_dmconfig.la

p_table.c p_table.h dm_action_table.c dm_action_table.h: $(top_srcdir)/yang/specs/*yang
	$(PYANG) --plugindir $(top_srcdir)/yang/pyang_plugin/ -p $(top_srcdir)/yang/specs -f OpenCPE $(top_srcdir)/yang/specs/*.yang


impl_list.csv:
	grep "VAR.*system\." $(srcdir)/*.[ch] | sed -e"s/\([^:]*\).*VAR:\s*\(.*\)\*\/.*/\1,\2/g" > impl_list.csv
