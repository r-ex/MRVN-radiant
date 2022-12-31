#pragma once

#include "bspfile_titanfall2.h"
#include "qmath.h"
#include <cstdint>
#include "remap.h"

void                        LoadR5BSPFile(const char* filename);
void                        WriteR5BSPFile(const char* filename);
void						CompileR5BSPFile();


namespace ApexLegends {
	void EmitStubs();

	void EmitEntity( const entity_t &e );
	void EmitMeshes( const entity_t &e );
	uint32_t EmitTextureData( shaderInfo_t shader );
	uint16_t EmitMaterialSort( uint32_t index );
	void EmitVertexUnlit( Shared::Vertex_t &vertex );
	void EmitVertexLitFlat( Shared::Vertex_t &vertex );
	void EmitVertexLitBump( Shared::Vertex_t &vertex );
	void EmitVertexUnlitTS( Shared::Vertex_t &vertex );
	std::size_t EmitObjReferences( Shared::visNode_t& node );
	int EmitVisChildrenOfTreeNode( Shared::visNode_t node );
	void EmitVisTree();
	void EmitLevelInfo();


	using Vertex_t = Vector3;

	using VertexNormal_t = Vector3;

	// 0x02
	struct TextureData_t {
		// was nameStringTableID pre-r5 but was changed to an offset instead of index
		int nameStringTableOffset;
		int width;
		int height;
		int flags;
	};

	// 0x47
	struct VertexUnlit_t {
		int posIdx;
		int nmlIdx;
		Vector2 texUV;
		int32_t negativeOne; // most likely vertex color - color32
	};

	// 0x48
	struct VertexLitFlat_t {
		int posIdx;
		int nmlIdx;
		Vector2 texUV;
		int32_t unknown0;
	};

	// 0x49
	struct VertexLitBump_t {
		int posIdx;
		int nmlIdx;
		Vector2 texUV;
		int32_t negativeOne;
		Vector2 uv1;
		uint8_t color[4];
	};

	// 0x4A
	struct VertexUnlitTS_t {
		int posIdx;
		int nmlIdx;
		Vector2 texUV;
		int32_t unknown0;
		int32_t unknown1;
	};

	// 0x4B
	// does not exist in r5
  struct VertexBlinnPhong_t {
		int posIdx;
		int nmlIdx;
		Vector2 texUV;
		Vector2 uv1;
	};

	// 0x50
	struct Mesh_t {
		uint32_t triOffset;
		uint16_t triCount;
		uint16_t unknown[8];
		uint16_t materialOffset;
		uint32_t flags;
	};

	// 0x52
	struct MaterialSort_t {
		uint16_t textureData;
		uint16_t lightmapIndex;
		uint16_t unknown0;
		uint16_t unknown1;
		uint32_t vertexOffset;
	};

	// 0x77
	struct CellAABBNode_t {
		Vector3 mins;
		uint32_t childCount : 8;
		uint32_t firstChild : 16;
		uint32_t childFlags : 8;
		Vector3 maxs;
		uint32_t objRefCount : 8;
		uint32_t objRefOffset : 16;
		uint32_t objRefFlags : 8;
	};


	// r1 struct:
	// struct dlevel_info_t
	// {
	// 	int firstDecalMeshIdx;
	// 	int firstTransMeshIdx;
	// 	int firstSkyMeshIdx;
	// 	int numStaticProps;
	// };

	// 0x7B
	struct LevelInfo_t {
		int32_t unk0;
		int32_t unk1;
		int32_t unk2;
		int32_t unk3;
		int32_t unk4;
		float unk5[3];
		int32_t modelCount;
	};

	struct dgamelumpheader_t {
		int lumpCount = 1;
	};

	struct dgamelump_t
	{
		char magic[4];
		unsigned short flags = 0;
		unsigned short version = 47;
		int fileofs;
		int filelen = 20;
		uint32_t zeros[5] = { 0,0,0,0,0 }; // these are not actually part of the struct so idrk why they are here
	};

	namespace Bsp {
		inline std::vector<TextureData_t> textureData;
		inline std::vector<VertexUnlit_t> vertexUnlitVertices;
		inline std::vector<VertexLitFlat_t> vertexLitFlatVertices;
		inline std::vector<VertexLitBump_t> vertexLitBumpVertices;
		inline std::vector<VertexUnlitTS_t> vertexUnlitTSVertices;
		inline std::vector<VertexBlinnPhong_t> vertexBlinnPhongVertices;
		inline std::vector<uint16_t> meshIndices;
		inline std::vector<Mesh_t> meshes;
		inline std::vector<MaterialSort_t> materialSorts;
		inline std::vector<CellAABBNode_t> cellAABBNodes;
		inline std::vector<int32_t> objReferences;
		inline std::vector<LevelInfo_t> levelInfo;
	
		// Stubs
		inline std::vector<uint8_t> textureData_stub;
		inline std::vector<uint8_t> vertices_stub;
		inline std::vector<uint8_t> lightprobeParentInfos_stub;
		inline std::vector<uint8_t> shadowEnvironments_stub;
		inline std::vector<uint8_t> models_stub;
		inline std::vector<uint8_t> surfaceNames_stub;
		inline std::vector<uint8_t> contentsMasks_stub;
		inline std::vector<uint8_t> surfaceProperties_stub;
		inline std::vector<uint8_t> bvhNodes_stub;
		inline std::vector<uint8_t> bvhNodeLeafData_stub;
		inline std::vector<uint8_t> entityPartitions_stub;
		inline std::vector<uint8_t> vertexNormals_stub;
		inline std::vector<uint8_t> gameLump_stub;
		inline std::vector<uint8_t> unknown25_stub;
		inline std::vector<uint8_t> unknown26_stub;
		inline std::vector<uint8_t> unknown27_stub;
		inline std::vector<uint8_t> cubemaps_stub;
		inline std::vector<uint8_t> worldLights_stub;
		inline std::vector<uint8_t> vertexUnlit_stub;
		inline std::vector<uint8_t> meshIndicies_stub;
		inline std::vector<uint8_t> meshes_stub;
		inline std::vector<uint8_t> meshBounds_stub;
		inline std::vector<uint8_t> materialSort_stub;
		inline std::vector<uint8_t> lightmapHeaders_stub;
		inline std::vector<uint8_t> tweakLights_stub;
		inline std::vector<uint8_t> lightmapDataSky_stub;
		inline std::vector<uint8_t> csmAABBNodes_stub;
		inline std::vector<uint8_t> cellAABBNodes_stub;
		inline std::vector<uint8_t> objReferences_stub;
		inline std::vector<uint8_t> objReferenceBounds_stub;
		inline std::vector<uint8_t> lightmapDataRTLPage_stub;
	}
}