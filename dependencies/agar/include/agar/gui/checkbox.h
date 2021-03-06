/*	Public domain	*/

#ifndef _AGAR_WIDGET_CHECKBOX_H_
#define _AGAR_WIDGET_CHECKBOX_H_

#include <agar/gui/widget.h>
#include <agar/gui/label.h>

#include <agar/gui/begin.h>

typedef struct ag_checkbox {
	struct ag_widget wid;
	Uint flags;
#define AG_CHECKBOX_HFILL	0x01
#define AG_CHECKBOX_VFILL	0x02
#define AG_CHECKBOX_EXPAND	(AG_CHECKBOX_HFILL|AG_CHECKBOX_VFILL)
#define AG_CHECKBOX_SET		0x04
	int state;		/* Default "state" binding */
	int spacing;		/* Spacing in pixels */
	AG_Label *lbl;		/* Text label */
} AG_Checkbox;

/* Begin generated block */
__BEGIN_DECLS
extern DECLSPEC AG_WidgetClass agCheckboxClass;
extern DECLSPEC AG_Checkbox *AG_CheckboxNew(void *, Uint, const char *, ...) FORMAT_ATTRIBUTE(printf, 3, 4);
extern DECLSPEC AG_Checkbox *AG_CheckboxNewS(void *, Uint, const char *);
extern DECLSPEC AG_Checkbox *AG_CheckboxNewFn(void *, Uint, const char *, AG_EventFn, const char *, ...);
extern DECLSPEC AG_Checkbox *AG_CheckboxNewInt(void *, Uint, const char *, int *);
extern DECLSPEC AG_Checkbox *AG_CheckboxNewFlag(void *, Uint, const char *, Uint *, Uint);
extern DECLSPEC AG_Checkbox *AG_CheckboxNewFlag32(void *, Uint, const char *, Uint32 *, Uint32);
extern DECLSPEC void AG_CheckboxSetFromFlags(void *, Uint, Uint *, const AG_FlagDescr *);
extern DECLSPEC void AG_CheckboxSetFromFlags32(void *, Uint, Uint32 *, const AG_FlagDescr *);
extern DECLSPEC void AG_CheckboxToggle(AG_Checkbox *);
__END_DECLS
/* Close generated block */

#include <agar/gui/close.h>
#endif /* _AGAR_WIDGET_CHECKBOX_H_ */
