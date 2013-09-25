/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#include "JSHTMLLIElement.h"

#include <wtf/GetPtr.h>

#include "HTMLLIElement.h"
#include "PlatformString.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashEntry JSHTMLLIElementTableEntries[] =
{
    { "constructor", JSHTMLLIElement::ConstructorAttrNum, DontDelete|DontEnum|ReadOnly, 0, 0 },
    { "type", JSHTMLLIElement::TypeAttrNum, DontDelete, 0, 0 },
    { "value", JSHTMLLIElement::ValueAttrNum, DontDelete, 0, 0 }
};

static const HashTable JSHTMLLIElementTable = 
{
    2, 3, JSHTMLLIElementTableEntries, 3
};

/* Hash table for constructor */

static const HashEntry JSHTMLLIElementConstructorTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLLIElementConstructorTable = 
{
    2, 1, JSHTMLLIElementConstructorTableEntries, 1
};

class JSHTMLLIElementConstructor : public DOMObject {
public:
    JSHTMLLIElementConstructor(ExecState* exec)
    {
        setPrototype(exec->lexicalInterpreter()->builtinObjectPrototype());
        putDirect(exec->propertyNames().prototype, JSHTMLLIElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLLIElementConstructor::info = { "HTMLLIElementConstructor", 0, &JSHTMLLIElementConstructorTable, 0 };

bool JSHTMLLIElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLLIElementConstructor, DOMObject>(exec, &JSHTMLLIElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLLIElementConstructor::getValueProperty(ExecState*, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(token);
}

/* Hash table for prototype */

static const HashEntry JSHTMLLIElementPrototypeTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLLIElementPrototypeTable = 
{
    2, 1, JSHTMLLIElementPrototypeTableEntries, 1
};

const ClassInfo JSHTMLLIElementPrototype::info = { "HTMLLIElementPrototype", 0, &JSHTMLLIElementPrototypeTable, 0 };

JSObject* JSHTMLLIElementPrototype::self(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLLIElementPrototype>(exec, "[[JSHTMLLIElement.prototype]]");
}

const ClassInfo JSHTMLLIElement::info = { "HTMLLIElement", &JSHTMLElement::info, &JSHTMLLIElementTable, 0 };

JSHTMLLIElement::JSHTMLLIElement(ExecState* exec, HTMLLIElement* impl)
    : JSHTMLElement(exec, impl)
{
    setPrototype(JSHTMLLIElementPrototype::self(exec));
}

bool JSHTMLLIElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLLIElement, JSHTMLElement>(exec, &JSHTMLLIElementTable, this, propertyName, slot);
}

JSValue* JSHTMLLIElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case TypeAttrNum: {
        HTMLLIElement* imp = static_cast<HTMLLIElement*>(impl());

        return jsString(imp->type());
    }
    case ValueAttrNum: {
        HTMLLIElement* imp = static_cast<HTMLLIElement*>(impl());

        return jsNumber(imp->value());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLLIElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value, int attr)
{
    lookupPut<JSHTMLLIElement, JSHTMLElement>(exec, propertyName, value, attr, &JSHTMLLIElementTable, this);
}

void JSHTMLLIElement::putValueProperty(ExecState* exec, int token, JSValue* value, int /*attr*/)
{
    switch (token) {
    case TypeAttrNum: {
        HTMLLIElement* imp = static_cast<HTMLLIElement*>(impl());

        imp->setType(valueToStringWithNullCheck(exec, value));
        break;
    }
    case ValueAttrNum: {
        HTMLLIElement* imp = static_cast<HTMLLIElement*>(impl());

        imp->setValue(value->toInt32(exec));
        break;
    }
    }
}

JSValue* JSHTMLLIElement::getConstructor(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLLIElementConstructor>(exec, "[[HTMLLIElement.constructor]]");
}

}
