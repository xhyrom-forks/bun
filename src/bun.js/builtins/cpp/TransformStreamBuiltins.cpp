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
#include "TransformStreamBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_transformStreamInitializeTransformStreamCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_transformStreamInitializeTransformStreamCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_transformStreamInitializeTransformStreamCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_transformStreamInitializeTransformStreamCodeLength = 2727;
static const JSC::Intrinsic s_transformStreamInitializeTransformStreamCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_transformStreamInitializeTransformStreamCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    let transformer = arguments[0];\n" \
    "\n" \
    "    //\n" \
    "    if (@isObject(transformer) && @getByIdDirectPrivate(transformer, \"TransformStream\"))\n" \
    "        return this;\n" \
    "\n" \
    "    let writableStrategy = arguments[1];\n" \
    "    let readableStrategy = arguments[2];\n" \
    "\n" \
    "    if (transformer === @undefined)\n" \
    "        transformer = null;\n" \
    "\n" \
    "    if (readableStrategy === @undefined)\n" \
    "        readableStrategy = { };\n" \
    "\n" \
    "    if (writableStrategy === @undefined)\n" \
    "        writableStrategy = { };\n" \
    "\n" \
    "    let transformerDict = { };\n" \
    "    if (transformer !== null) {\n" \
    "        if (\"start\" in transformer) {\n" \
    "            transformerDict[\"start\"] = transformer[\"start\"];\n" \
    "            if (typeof transformerDict[\"start\"] !== \"function\")\n" \
    "                @throwTypeError(\"transformer.start should be a function\");\n" \
    "        }\n" \
    "        if (\"transform\" in transformer) {\n" \
    "            transformerDict[\"transform\"] = transformer[\"transform\"];\n" \
    "            if (typeof transformerDict[\"transform\"] !== \"function\")\n" \
    "                @throwTypeError(\"transformer.transform should be a function\");\n" \
    "        }\n" \
    "        if (\"flush\" in transformer) {\n" \
    "            transformerDict[\"flush\"] = transformer[\"flush\"];\n" \
    "            if (typeof transformerDict[\"flush\"] !== \"function\")\n" \
    "                @throwTypeError(\"transformer.flush should be a function\");\n" \
    "        }\n" \
    "\n" \
    "        if (\"readableType\" in transformer)\n" \
    "            @throwRangeError(\"TransformStream transformer has a readableType\");\n" \
    "        if (\"writableType\" in transformer)\n" \
    "            @throwRangeError(\"TransformStream transformer has a writableType\");\n" \
    "    }\n" \
    "\n" \
    "    const readableHighWaterMark = @extractHighWaterMark(readableStrategy, 0);\n" \
    "    const readableSizeAlgorithm = @extractSizeAlgorithm(readableStrategy);\n" \
    "\n" \
    "    const writableHighWaterMark = @extractHighWaterMark(writableStrategy, 1);\n" \
    "    const writableSizeAlgorithm = @extractSizeAlgorithm(writableStrategy);\n" \
    "\n" \
    "    const startPromiseCapability = @newPromiseCapability(@Promise);\n" \
    "    @initializeTransformStream(this, startPromiseCapability.@promise, writableHighWaterMark, writableSizeAlgorithm, readableHighWaterMark, readableSizeAlgorithm);\n" \
    "    @setUpTransformStreamDefaultControllerFromTransformer(this, transformer, transformerDict);\n" \
    "\n" \
    "    if (\"start\" in transformerDict) {\n" \
    "        const controller = @getByIdDirectPrivate(this, \"controller\");\n" \
    "        const startAlgorithm = () => @promiseInvokeOrNoopMethodNoCatch(transformer, transformerDict[\"start\"], [controller]);\n" \
    "        startAlgorithm().@then(() => {\n" \
    "            //\n" \
    "            startPromiseCapability.@resolve.@call();\n" \
    "        }, (error) => {\n" \
    "            startPromiseCapability.@reject.@call(@undefined, error);\n" \
    "        });\n" \
    "    } else\n" \
    "        startPromiseCapability.@resolve.@call();\n" \
    "\n" \
    "    return this;\n" \
    "})\n" \
;

const JSC::ConstructAbility s_transformStreamReadableCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_transformStreamReadableCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_transformStreamReadableCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_transformStreamReadableCodeLength = 190;
static const JSC::Intrinsic s_transformStreamReadableCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_transformStreamReadableCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isTransformStream(this))\n" \
    "        throw @makeThisTypeError(\"TransformStream\", \"readable\");\n" \
    "\n" \
    "    return @getByIdDirectPrivate(this, \"readable\");\n" \
    "})\n" \
;

const JSC::ConstructAbility s_transformStreamWritableCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_transformStreamWritableCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_transformStreamWritableCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_transformStreamWritableCodeLength = 190;
static const JSC::Intrinsic s_transformStreamWritableCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_transformStreamWritableCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isTransformStream(this))\n" \
    "        throw @makeThisTypeError(\"TransformStream\", \"writable\");\n" \
    "\n" \
    "    return @getByIdDirectPrivate(this, \"writable\");\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().transformStreamBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().transformStreamBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_TRANSFORMSTREAM_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
