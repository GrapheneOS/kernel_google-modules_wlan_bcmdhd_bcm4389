/*
 * Cellular channel avoidance implementation
 *
 * $ Copyright Open Broadcom $
 *
 *
 * <<Broadcom-WL-IPTag/Dual:>>
 */

#ifndef _wl_cfg_cellavoid_h_
#define _wl_cfg_cellavoid_h_

#include <linux/netdevice.h>
#include <linux/nl80211.h>

#define MAX_AP_INTERFACE	2
#define MAX_STA_INTERFACE	2

extern int wl_cellavoid_init(struct bcm_cfg80211 *cfg);
extern void wl_cellavoid_deinit(struct bcm_cfg80211 *cfg);
extern int wl_cellavoid_reinit(struct bcm_cfg80211 *cfg);
extern void wl_cellavoid_sync_lock(struct bcm_cfg80211 *cfg);
extern void wl_cellavoid_sync_unlock(struct bcm_cfg80211 *cfg);
extern int wl_cfgvendor_cellavoid_set_cell_channels(struct wiphy *wiphy,
	struct wireless_dev *wdev, const void  *data, int len);
extern int wl_cellavoid_set_requested_freq_bands(struct net_device *ndev,
	void *cai, u32 *pElem_freq, u32 freq_list_len);
extern void wl_cellavoid_clear_requested_freq_bands(struct net_device *ndev,
	void *cai);
extern bool wl_cellavoid_operation_allowed(void *cai,
	chanspec_t chanspec, enum nl80211_iftype type);
extern void wl_cellavoid_free_csa_info(void *cai,
	struct net_device *ndev);
extern chanspec_t wl_cellavoid_find_chspec_fromband(void *cai, int band);
extern chanspec_t wl_cellavoid_find_widechspec_fromchspec(void *cai, chanspec_t chanspec);
extern void wl_cellavoid_set_csa_done(void *cai);
extern bool wl_cellavoid_mandatory_isset(void *cai, enum nl80211_iftype type);
extern bool wl_cellavoid_is_safe(void *cai, chanspec_t chanspec);

#endif /* _wl_cfg_cellavoid_h_ */
