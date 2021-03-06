/*
 * Copyright (C) 2006 Nikolas Zimmermann <zimmermann@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"

#if ENABLE(SVG)
#include "JSSVGPathSeg.h"
#include "JSSVGPathSegArcAbs.h"
#include "JSSVGPathSegArcRel.h"
#include "JSSVGPathSegClosePath.h"
#include "JSSVGPathSegCurvetoCubicAbs.h"
#include "JSSVGPathSegCurvetoCubicRel.h"
#include "JSSVGPathSegCurvetoCubicSmoothAbs.h"
#include "JSSVGPathSegCurvetoCubicSmoothRel.h"
#include "JSSVGPathSegCurvetoQuadraticAbs.h"
#include "JSSVGPathSegCurvetoQuadraticRel.h"
#include "JSSVGPathSegCurvetoQuadraticSmoothAbs.h"
#include "JSSVGPathSegCurvetoQuadraticSmoothRel.h"
#include "JSSVGPathSegLinetoAbs.h"
#include "JSSVGPathSegLinetoRel.h"
#include "JSSVGPathSegLinetoHorizontalAbs.h"
#include "JSSVGPathSegLinetoHorizontalRel.h"
#include "JSSVGPathSegLinetoVerticalAbs.h"
#include "JSSVGPathSegLinetoVerticalRel.h"
#include "JSSVGPathSegMovetoAbs.h"
#include "JSSVGPathSegMovetoRel.h"

#include "kjs_binding.h"

#include "SVGPathSeg.h"
#include "SVGPathSegArc.h"
#include "SVGPathSegClosePath.h"
#include "SVGPathSegCurvetoCubic.h"
#include "SVGPathSegCurvetoCubicSmooth.h"
#include "SVGPathSegCurvetoQuadratic.h"
#include "SVGPathSegCurvetoQuadraticSmooth.h"
#include "SVGPathSegLineto.h"
#include "SVGPathSegLinetoHorizontal.h"
#include "SVGPathSegLinetoVertical.h"
#include "SVGPathSegMoveto.h"

using namespace KJS;

namespace WebCore {

JSValue* toJS(ExecState* exec, SVGPathSeg* obj)
{
    if (!obj)
        return jsNull();
    
    switch (obj->pathSegType()) {
    case SVGPathSeg::PATHSEG_CLOSEPATH:
        return cacheDOMObject<SVGPathSegClosePath, JSSVGPathSegClosePath>(exec, static_cast<SVGPathSegClosePath*>(obj));
    case SVGPathSeg::PATHSEG_MOVETO_ABS:
        return cacheDOMObject<SVGPathSegMovetoAbs, JSSVGPathSegMovetoAbs>(exec, static_cast<SVGPathSegMovetoAbs*>(obj));
    case SVGPathSeg::PATHSEG_MOVETO_REL:
        return cacheDOMObject<SVGPathSegMovetoRel, JSSVGPathSegMovetoRel>(exec, static_cast<SVGPathSegMovetoRel*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_ABS:
        return cacheDOMObject<SVGPathSegLinetoAbs, JSSVGPathSegLinetoAbs>(exec, static_cast<SVGPathSegLinetoAbs*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_REL:
        return cacheDOMObject<SVGPathSegLinetoRel, JSSVGPathSegLinetoRel>(exec, static_cast<SVGPathSegLinetoRel*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_CUBIC_ABS:
        return cacheDOMObject<SVGPathSegCurvetoCubicAbs, JSSVGPathSegCurvetoCubicAbs>(exec, static_cast<SVGPathSegCurvetoCubicAbs*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_CUBIC_REL:
        return cacheDOMObject<SVGPathSegCurvetoCubicRel, JSSVGPathSegCurvetoCubicRel>(exec, static_cast<SVGPathSegCurvetoCubicRel*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_QUADRATIC_ABS:
        return cacheDOMObject<SVGPathSegCurvetoQuadraticAbs, JSSVGPathSegCurvetoQuadraticAbs>(exec, static_cast<SVGPathSegCurvetoQuadraticAbs*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_QUADRATIC_REL:
        return cacheDOMObject<SVGPathSegCurvetoQuadraticRel, JSSVGPathSegCurvetoQuadraticRel>(exec, static_cast<SVGPathSegCurvetoQuadraticRel*>(obj));
    case SVGPathSeg::PATHSEG_ARC_ABS:
        return cacheDOMObject<SVGPathSegArcAbs, JSSVGPathSegArcAbs>(exec, static_cast<SVGPathSegArcAbs*>(obj));
    case SVGPathSeg::PATHSEG_ARC_REL:
        return cacheDOMObject<SVGPathSegArcRel, JSSVGPathSegArcRel>(exec, static_cast<SVGPathSegArcRel*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_HORIZONTAL_ABS:
        return cacheDOMObject<SVGPathSegLinetoHorizontalAbs, JSSVGPathSegLinetoHorizontalAbs>(exec, static_cast<SVGPathSegLinetoHorizontalAbs*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_HORIZONTAL_REL:
        return cacheDOMObject<SVGPathSegLinetoHorizontalRel, JSSVGPathSegLinetoHorizontalRel>(exec, static_cast<SVGPathSegLinetoHorizontalRel*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_VERTICAL_ABS:
        return cacheDOMObject<SVGPathSegLinetoVerticalAbs, JSSVGPathSegLinetoVerticalAbs>(exec, static_cast<SVGPathSegLinetoVerticalAbs*>(obj));
    case SVGPathSeg::PATHSEG_LINETO_VERTICAL_REL:
        return cacheDOMObject<SVGPathSegLinetoVerticalRel, JSSVGPathSegLinetoVerticalRel>(exec, static_cast<SVGPathSegLinetoVerticalRel*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_CUBIC_SMOOTH_ABS:
        return cacheDOMObject<SVGPathSegCurvetoCubicSmoothAbs, JSSVGPathSegCurvetoCubicSmoothAbs>(exec, static_cast<SVGPathSegCurvetoCubicSmoothAbs*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_CUBIC_SMOOTH_REL:
        return cacheDOMObject<SVGPathSegCurvetoCubicSmoothRel, JSSVGPathSegCurvetoCubicSmoothRel>(exec, static_cast<SVGPathSegCurvetoCubicSmoothRel*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_QUADRATIC_SMOOTH_ABS:
        return cacheDOMObject<SVGPathSegCurvetoQuadraticSmoothAbs, JSSVGPathSegCurvetoQuadraticSmoothAbs>(exec, static_cast<SVGPathSegCurvetoQuadraticSmoothAbs*>(obj));
    case SVGPathSeg::PATHSEG_CURVETO_QUADRATIC_SMOOTH_REL:
        return cacheDOMObject<SVGPathSegCurvetoQuadraticSmoothRel, JSSVGPathSegCurvetoQuadraticSmoothRel>(exec, static_cast<SVGPathSegCurvetoQuadraticSmoothRel*>(obj));
    case SVGPathSeg::PATHSEG_UNKNOWN:
    default:
        return cacheDOMObject<SVGPathSeg, JSSVGPathSeg>(exec, obj);
    }
}

}

#endif // ENABLE(SVG)

// vim:ts=4:noet
