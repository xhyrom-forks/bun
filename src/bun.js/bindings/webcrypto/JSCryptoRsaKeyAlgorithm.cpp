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

#if ENABLE(WEB_CRYPTO)

#include "JSCryptoRsaKeyAlgorithm.h"

#include "JSDOMConvertBufferSource.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMGlobalObject.h"
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/ObjectConstructor.h>

namespace WebCore {
using namespace JSC;

#if ENABLE(WEB_CRYPTO)

template<> CryptoRsaKeyAlgorithm convertDictionary<CryptoRsaKeyAlgorithm>(JSGlobalObject& lexicalGlobalObject, JSValue value)
{
    VM& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool isNullOrUndefined = value.isUndefinedOrNull();
    auto* object = isNullOrUndefined ? nullptr : value.getObject();
    if (UNLIKELY(!isNullOrUndefined && !object)) {
        throwTypeError(&lexicalGlobalObject, throwScope);
        return {};
    }
    CryptoRsaKeyAlgorithm result;
    JSValue nameValue;
    if (isNullOrUndefined)
        nameValue = jsUndefined();
    else {
        nameValue = object->get(&lexicalGlobalObject, vm.propertyNames->name);
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!nameValue.isUndefined()) {
        result.name = convert<IDLDOMString>(lexicalGlobalObject, nameValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "name"_s, "CryptoRsaKeyAlgorithm"_s, "DOMString"_s);
        return {};
    }
    JSValue modulusLengthValue;
    if (isNullOrUndefined)
        modulusLengthValue = jsUndefined();
    else {
        modulusLengthValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "modulusLength"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!modulusLengthValue.isUndefined()) {
        result.modulusLength = convert<IDLUnsignedLong>(lexicalGlobalObject, modulusLengthValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "modulusLength"_s, "CryptoRsaKeyAlgorithm"_s, "unsigned long"_s);
        return {};
    }
    JSValue publicExponentValue;
    if (isNullOrUndefined)
        publicExponentValue = jsUndefined();
    else {
        publicExponentValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "publicExponent"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!publicExponentValue.isUndefined()) {
        result.publicExponent = convert<IDLUint8Array>(lexicalGlobalObject, publicExponentValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "publicExponent"_s, "CryptoRsaKeyAlgorithm"_s, "Uint8Array"_s);
        return {};
    }
    return result;
}

JSC::JSObject* convertDictionaryToJS(JSC::JSGlobalObject& lexicalGlobalObject, JSDOMGlobalObject& globalObject, const CryptoRsaKeyAlgorithm& dictionary)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);

    auto result = constructEmptyObject(&lexicalGlobalObject, globalObject.objectPrototype());

    auto nameValue = toJS<IDLDOMString>(lexicalGlobalObject, throwScope, dictionary.name);
    RETURN_IF_EXCEPTION(throwScope, {});
    result->putDirect(vm, vm.propertyNames->name, nameValue);
    auto modulusLengthValue = toJS<IDLUnsignedLong>(lexicalGlobalObject, throwScope, dictionary.modulusLength);
    RETURN_IF_EXCEPTION(throwScope, {});
    result->putDirect(vm, JSC::Identifier::fromString(vm, "modulusLength"_s), modulusLengthValue);
    auto publicExponentValue = toJS<IDLUint8Array>(lexicalGlobalObject, globalObject, throwScope, dictionary.publicExponent);
    RETURN_IF_EXCEPTION(throwScope, {});
    result->putDirect(vm, JSC::Identifier::fromString(vm, "publicExponent"_s), publicExponentValue);
    return result;
}

#endif

} // namespace WebCore

#endif // ENABLE(WEB_CRYPTO)
