#include<Windows.h>
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << "," << dest.y << "," << dest.z <<","<<dest.w<< ")";
	return os;
}

int main()
{
	cout.setf(ios_base::boolalpha);
	if (!XMVerifyCPUSupport)
	{
		cout << "directx math not supported" << endl;
		return 0;
	}
	XMVECTOR p = XMVectorZero();//返回零向量
	XMVECTOR q = XMVectorSplatOne();//返回(1,1,1,1)
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);//返回(value,value,value,value);
	XMVECTOR w = XMVectorSplatZ(u);//返回(Vz,Vz,Vz,Vz)

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;

	return 0;
}