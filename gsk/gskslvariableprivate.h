/* GTK - The GIMP Toolkit
 *
 * Copyright © 2017 Benjamin Otte <otte@gnome.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GSK_SL_VARIABLE_PRIVATE_H__
#define __GSK_SL_VARIABLE_PRIVATE_H__

#include <glib.h>

#include "gsk/gsksltypesprivate.h"
#include "gsk/gskspvenumsprivate.h"

G_BEGIN_DECLS

GskSlVariable *         gsk_sl_variable_new                     (const char             *name,
                                                                 GskSlType              *type,
                                                                 const GskSlQualifier   *qualifier,
                                                                 GskSlValue             *initial_value);
GskSlVariable *         gsk_sl_variable_new_block_member        (GskSlVariable          *block,
                                                                 guint                   member_id);
GskSlVariable *         gsk_sl_variable_new_builtin             (const char             *name,
                                                                 GskSlType              *type,
                                                                 const GskSlQualifier   *qualifier,
                                                                 GskSpvBuiltIn           builtin);

GskSlVariable *         gsk_sl_variable_ref                     (GskSlVariable          *variable);
void                    gsk_sl_variable_unref                   (GskSlVariable          *variable);

void                    gsk_sl_variable_print                   (const GskSlVariable    *variable,
                                                                 GskSlPrinter           *printer);

GskSlType *             gsk_sl_variable_get_type                (const GskSlVariable    *variable);
const GskSlQualifier *  gsk_sl_variable_get_qualifier           (const GskSlVariable    *variable);
const char *            gsk_sl_variable_get_name                (const GskSlVariable    *variable);
const GskSlValue *      gsk_sl_variable_get_initial_value       (const GskSlVariable    *variable);
gboolean                gsk_sl_variable_is_constant             (const GskSlVariable    *variable);

GskSpvAccessChain *     gsk_sl_variable_get_access_chain        (GskSlVariable          *variable,
                                                                 GskSpvWriter           *writer);
                                                                 
guint32                 gsk_sl_variable_write_spv               (const GskSlVariable    *variable,
                                                                 GskSpvWriter           *writer);
guint32                 gsk_sl_variable_load_spv                (GskSlVariable          *variable,
                                                                 GskSpvWriter           *writer);

void                    gsk_spv_access_chain_free               (GskSpvAccessChain      *chain);
void                    gsk_spv_access_chain_add_index          (GskSpvAccessChain      *chain,
                                                                 GskSlType              *type,
                                                                 guint32                 index_id);
void                    gsk_spv_access_chain_add_dynamic_index  (GskSpvAccessChain      *chain,
                                                                 GskSlType              *type,
                                                                 GskSlExpression        *expr);
void                    gsk_spv_access_chain_swizzle            (GskSpvAccessChain      *chain,
                                                                 const guint            *indexes,
                                                                 guint                   n_indexes);
gboolean                gsk_spv_access_chain_has_swizzle        (GskSpvAccessChain      *chain);
guint32                 gsk_spv_access_chain_load               (GskSpvAccessChain      *chain);
void                    gsk_spv_access_chain_store              (GskSpvAccessChain      *chain,
                                                                 guint32                 value);

G_END_DECLS

#endif /* __GSK_SL_VARIABLE_PRIVATE_H__ */