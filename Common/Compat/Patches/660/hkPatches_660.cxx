/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

// Common specific product patches applied to release 660.
// This file is #included by hkPatches_660.cpp

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkGeometry", 0)
	HK_PATCH_MEMBER_ADDED("vertices", TYPE_ARRAY_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("triangles", TYPE_ARRAY_STRUCT, "hkGeometryTriangle", 0)
	HK_PATCH_DEPENDS("hkGeometryTriangle", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkGeometryTriangle", 0)
	HK_PATCH_MEMBER_ADDED("a", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("b", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("c", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("material", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()


// 7.0
HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkxVertexBufferVertexData", 0)
	HK_PATCH_MEMBER_ADDED("vectorData", TYPE_ARRAY_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("floatData", TYPE_ARRAY_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint32Data", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint16Data", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint8Data", TYPE_ARRAY_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("numVerts", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("vectorStride", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("floatStride", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint32Stride", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint16Stride", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("uint8Stride", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexDescriptionElementDecl", 0, "hkxVertexDescriptionElementDecl", 1)
	HK_PATCH_MEMBER_ADDED("byteStride", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexBuffer", 0, "hkxVertexBuffer", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("data", TYPE_STRUCT, "hkxVertexBufferVertexData", 0)
	HK_PATCH_MEMBER_ADDED("desc", TYPE_STRUCT, "hkxVertexDescription", 0)
	HK_PATCH_FUNCTION(hkxVertexBuffer_0_to_1)
	HK_PATCH_MEMBER_REMOVED("vertexData", TYPE_ARRAY_STRUCT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("vertexDesc", TYPE_OBJECT, "hkxVertexDescription", 0)
	HK_PATCH_DEPENDS("hkxVertexBufferVertexData", 0)
	HK_PATCH_DEPENDS("hkxVertexDescriptionElementDecl", 1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexDescription", 0, "hkxVertexDescription", 1)
	HK_PATCH_MEMBER_REMOVED("stride", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()


HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkxEnum", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("items", TYPE_ARRAY_STRUCT, "hkxEnumItem", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkxEnumItem", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkxEnumItem", 0)
	HK_PATCH_MEMBER_ADDED("value", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("name", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4C1T10", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4C1T12", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u5", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v5", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4C1T2", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4C1T6", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4C1T2", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4C1T6", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4Q4", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("weights", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("indices", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("qu0", TYPE_TUPLE_INT, HK_NULL, 2)
	HK_PATCH_MEMBER_REMOVED("qu1", TYPE_TUPLE_INT, HK_NULL, 2)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4T6", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4C1T10", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4C1Q2", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("weights", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("indices", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuse", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("qu", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("qv", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4C1T4", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4W4I4C1T8", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4C1Q2", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("weights", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("indices", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuse", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("qu", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("qv", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4C1T4", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4C1T8", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4T4B4T4", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("tangent", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("binormal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4C1T12", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseA", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v3", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v4", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u5", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v5", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("diffuseB", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedString", 0, "hkxSparselyAnimatedString", 1)
	HK_PATCH_MEMBER_RENAMED("strings", "old_strings")
	HK_PATCH_MEMBER_ADDED("strings", TYPE_ARRAY_CSTRING, HK_NULL, 0)
	HK_PATCH_FUNCTION(hkxSparselyAnimatedString_0_to_1)
	HK_PATCH_MEMBER_REMOVED("old_strings", TYPE_ARRAY_STRUCT, "hkxSparselyAnimatedStringStringType", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedStringStringType", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("string", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4T2", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexP4N4W4I4T6", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("position", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("normal", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("w3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i0", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i1", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i2", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("i3", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v0", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v1", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("u2", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("v2", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxTextureInplace", 0, "hkxTextureInplace", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxIndexBuffer", 0, "hkxIndexBuffer", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexIntDataChannel", 0, "hkxVertexIntDataChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxMaterialEffect", 0, "hkxMaterialEffect", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxMeshSection", 0, "hkxMeshSection", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxEdgeSelectionChannel", 0, "hkxEdgeSelectionChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxScene", 0, "hkxScene", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedString", 1, "hkxSparselyAnimatedString", 2)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedBool", 0, "hkxSparselyAnimatedBool", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedInt", 0, "hkxSparselyAnimatedInt", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxMesh", 0, "hkxMesh", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxAnimatedFloat", 0, "hkxAnimatedFloat", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxTriangleSelectionChannel", 0, "hkxTriangleSelectionChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSparselyAnimatedEnum", 0, "hkxSparselyAnimatedEnum", 1)
	HK_PATCH_MEMBER_REMOVED("type", TYPE_OBJECT, "hkClassEnum", 0)
	HK_PATCH_MEMBER_ADDED("enum", TYPE_OBJECT, "hkxEnum", 0)
	HK_PATCH_DEPENDS("hkClassEnum", 0)
	HK_PATCH_DEPENDS("hkxEnum", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxMaterialShaderSet", 0, "hkxMaterialShaderSet", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexSelectionChannel", 0, "hkxVertexSelectionChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxAnimatedQuaternion", 0, "hkxAnimatedQuaternion", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexFloatDataChannel", 0, "hkxVertexFloatDataChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxTextureFile", 0, "hkxTextureFile", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxLight", 0, "hkxLight", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxAnimatedMatrix", 0, "hkxAnimatedMatrix", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxAttributeHolder", 0, "hkxAttributeHolder", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkAlignSceneToNodeOptions", 0, "hkAlignSceneToNodeOptions", 1)
	HK_PATCH_MEMBER_REMOVED("nodeName", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("nodeName", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxMaterialShader", 0, "hkxMaterialShader", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxSkinBinding", 0, "hkxSkinBinding", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxCamera", 0, "hkxCamera", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxVertexVectorDataChannel", 0, "hkxVertexVectorDataChannel", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkxAnimatedVector", 0, "hkxAnimatedVector", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkMemoryResourceHandleExternalLink", 0, "hkMemoryResourceHandleExternalLink", 1)
	HK_PATCH_MEMBER_REMOVED("externalIdIsAllocated", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("memberNameIsAllocated", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkMemoryResourceHandle", 0, "hkMemoryResourceHandle", 1)
	HK_PATCH_MEMBER_REMOVED("nameIsAllocated", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkMemoryResourceContainer", 0, "hkMemoryResourceContainer", 1)
	HK_PATCH_MEMBER_REMOVED("nameIsAllocated", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkMeshSectionCinfo", 0, "hkMeshSectionCinfo", 1)
	HK_PATCH_MEMBER_REMOVED("indices", TYPE_OBJECT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkMeshSection", 0, "hkMeshSection", 1)
	HK_PATCH_MEMBER_REMOVED("indices", TYPE_OBJECT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkxEnvironment", 0, "hkxEnvironment", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

HK_PATCH_BEGIN("hkMemoryResourceHandle", 1, "hkMemoryResourceHandle", 2)
	HK_PATCH_MEMBER_REMOVED("objectIsRerencedObject", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkAlignSceneToNodeOptions", 1, "hkAlignSceneToNodeOptions", 2)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
HK_PATCH_END()

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20130718)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */
