#include <iostream>
#include <memory>
#include "geometry.h"
using namespace std;

class Object
{

};

class PolygonMesh : public Object
{
private:
	uint32_t numFaces; // number of faces
	std::unique_ptr<Vec3f[]> pts; // face index
	std::unique_ptr<uint32_t []> faceIndex; // face index
	std::unique_ptr<uint32_t []> vertexIndex; // vertex index
	std::unique_ptr<Vec3f[]> P;

public:
	PolygonMesh(uint32_t nfaces, uint32_t *fi, uint32_t *vi, Vec3f *p)
		: numFaces(nfaces), faceIndex(NULL), vertexIndex(NULL), P(NULL)
		// new PolygonMesh(numFaces, faceIndex, vertexIndex, P);
	{
		uint32_t vertArraySize = 0;
		uint32_t maxVertexIndex = 0, index = 0;

		for (uint32_t i = 0; i < numFaces; ++i)
		{
			vertArraySize += fi[i];
			for (uint32_t j = 0; j < fi[i]; ++j)
			{
				if (vi[index + j] > maxVertexIndex)
					maxVertexIndex = vi[index + j];
			}
			index += fi[i];
		}
		// vertArraySize = fi ���ҵ��� �� ��.
		// face index = {4, 4}

		// maxVertexIndex = vi ���ҵ� �� �ִ밪.
		// uint32_t vertexIndex[8] = { 0,1,2,3,0,3,4,5 };

		maxVertexIndex += 1; 
		// �迭�� ������ = �����Ϸ��� �ִ� index + 1
		// �迭�� �ε����� 0���� �����Ѵ�

		pts = std::unique_ptr<Vec3f[]>(new Vec3f[maxVertexIndex]);
		
		for (uint32_t i = 0; i<maxVertexIndex; ++i) P[i] = p[i];
		
		vertexIndex = std::unique_ptr<uint32_t []>(new uint32_t[maxVertexIndex]);
		for (uint32_t i = 0; i < maxVertexIndex; ++i) vertexIndex[i] = vi[i];

		faceIndex = std::unique_ptr<uint32_t []>(new uint32_t[numFaces]);
		for (uint32_t i = 0; i < maxVertexIndex; ++i) faceIndex[i] = fi[i];
	}
	
	~PolygonMesh() { /* release memory */ }
	
	bool intersect() const {}
	void getSurfaceData() const {}
};

void TriangleMesh
(
	const uint32_t nfaces,
	const uint32_t *faceIndex,
	const uint32_t *vertsIndex,
	const Vec3f *verts
)
/*(
	const uint32_t nfaces,
	const std::unique_ptr<uint32_t []> &faceIndex,
	const std::unique_ptr<uint32_t []> &vertsIndex,
	const std::unique_ptr<Vec3f []> &verts,
	const std::unique_ptr<Vec3f []> &normals = nullptr,
	const std::unique_ptr<Vec2f []> &st = nullptr
	// : numTris(0)
)*/
{
	uint32_t numTris = 0;
	uint32_t k = 0, maxVertIndex = 0;

	// find out how many triangles we need to create for this mesh
	for (uint32_t i = 0; i < nfaces; ++i)
	{
		numTris += faceIndex[i] - 2; // �� n������ face���� �ﰢ���� n-2 �� ���������.
		for (uint32_t j = 0; j < faceIndex[i]; ++j)
		{
			if (vertsIndex[k + j] > maxVertIndex)
				maxVertIndex = vertsIndex[k + j];
			// vertsIndex �迭 �� �ִ밪�� maxVertIndex�� ����.
		}
		k += faceIndex[i]; // k�� offset�� ������ �Ѵ�
	}
	maxVertIndex++;

	// allocate memory to store the position of the mesh vertices
	// maxVertIndex �������� �迭�� vertex�� �߰��� ��.
	std::unique_ptr<Vec3f[]> P = std::unique_ptr<Vec3f[]>(new Vec3f[maxVertIndex]);
	for (uint32_t i = 0; i < maxVertIndex; ++i)
	{
		P[i] = verts[i];
		cout << verts[i] << endl;
	}

	// allocate memory to store triangle indices
	std::unique_ptr<Vec3f[]> trisIndex = std::unique_ptr<Vec3f[]>(new Vec3f[numTris*3]);
	// vertex ������ �״�� ����ϸ� ��.
	// �ﰢ���� ��� ����Ǿ��ִ����� �����ؾ� �Ѵ�.
	uint32_t l = 0; // for index
	
	// generate the triangle index array
	for (uint32_t i = 0, k = 0; i < nfaces; ++i)
	{
		cout << "i: " << i << ", k: " << k << endl;

		for (uint32_t j = 0; j < faceIndex[i] - 2; ++j)
		{
			trisIndex[l] = vertsIndex[k];
			cout << "trisIndex " << l << ": vertsIndex: " << k << endl;
			trisIndex[l + 1] = vertsIndex[k + j + 1];
			cout << "trisIndex " << l+1 << ": vertsIndex: " << k+j+1 << endl;
			trisIndex[l + 2] = vertsIndex[k + j + 2];
			cout << "trisIndex " << l+2 << ": vertsIndex: " << k+j+2 << endl;
			l += 3;
		}
		k += faceIndex[i];
		
		cout << endl;
	}
}

int main()
{
	uint32_t numFaces = 2;
	uint32_t faceIndex[2] = { 4,4 };
	uint32_t vertexIndex[8] = { 0,1,2,3,0,3,4,5 };
	Vec3f P[6] =
	{
		Vec3f(-5, -5, 5), Vec3f(5, -5, 5),
		Vec3f(5, -5,-5), Vec3f(-5, -5, -5),
		Vec3f(-5, 5, -5), Vec3f(-5, 5, 5),
	};
	
	TriangleMesh(numFaces, faceIndex, vertexIndex, P);

	PolygonMesh *mesh = new PolygonMesh(numFaces, faceIndex, vertexIndex, P);
}