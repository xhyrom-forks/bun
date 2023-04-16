/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "ReadableStreamBYOBRequestBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSObjectInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeLength = 306;
static const JSC::Intrinsic s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCode =
    "(function (controller, view)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (arguments.length !== 3 && arguments[2] !== @isReadableStream)\n" \
    "        @throwTypeError(\"ReadableStreamBYOBRequest constructor should not be called directly\");\n" \
    "\n" \
    "    return @privateInitializeReadableStreamBYOBRequest.@call(this, controller, view);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamBYOBRequestRespondCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamBYOBRequestRespondCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamBYOBRequestRespondCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamBYOBRequestRespondCodeLength = 504;
static const JSC::Intrinsic s_readableStreamBYOBRequestRespondCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamBYOBRequestRespondCode =
    "(function (bytesWritten)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamBYOBRequest(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStreamBYOBRequest\", \"respond\");\n" \
    "\n" \
    "    if (@getByIdDirectPrivate(this, \"associatedReadableByteStreamController\") === @undefined)\n" \
    "        @throwTypeError(\"ReadableStreamBYOBRequest.associatedReadableByteStreamController is undefined\");\n" \
    "\n" \
    "    return @readableByteStreamControllerRespond(@getByIdDirectPrivate(this, \"associatedReadableByteStreamController\"), bytesWritten);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamBYOBRequestRespondWithNewViewCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamBYOBRequestRespondWithNewViewCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamBYOBRequestRespondWithNewViewCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamBYOBRequestRespondWithNewViewCodeLength = 691;
static const JSC::Intrinsic s_readableStreamBYOBRequestRespondWithNewViewCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamBYOBRequestRespondWithNewViewCode =
    "(function (view)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamBYOBRequest(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStreamBYOBRequest\", \"respond\");\n" \
    "\n" \
    "    if (@getByIdDirectPrivate(this, \"associatedReadableByteStreamController\") === @undefined)\n" \
    "        @throwTypeError(\"ReadableStreamBYOBRequest.associatedReadableByteStreamController is undefined\");\n" \
    "\n" \
    "    if (!@isObject(view))\n" \
    "        @throwTypeError(\"Provided view is not an object\");\n" \
    "\n" \
    "    if (!@ArrayBuffer.@isView(view))\n" \
    "        @throwTypeError(\"Provided view is not an ArrayBufferView\");\n" \
    "\n" \
    "    return @readableByteStreamControllerRespondWithNewView(@getByIdDirectPrivate(this, \"associatedReadableByteStreamController\"), view);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamBYOBRequestViewCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamBYOBRequestViewCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamBYOBRequestViewCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamBYOBRequestViewCodeLength = 204;
static const JSC::Intrinsic s_readableStreamBYOBRequestViewCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamBYOBRequestViewCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamBYOBRequest(this))\n" \
    "        throw @makeGetterTypeError(\"ReadableStreamBYOBRequest\", \"view\");\n" \
    "\n" \
    "    return @getByIdDirectPrivate(this, \"view\");\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().readableStreamBYOBRequestBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().readableStreamBYOBRequestBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_READABLESTREAMBYOBREQUEST_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
