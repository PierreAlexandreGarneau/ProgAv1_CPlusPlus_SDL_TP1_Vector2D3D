#include "stdafx.h"
#include "CppUnitTest.h"

#include "Vector2D.h"
#include "Vector3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP1_Tests
{		
	TEST_CLASS(Vector2DTest)
	{
	public:
		TEST_METHOD(AddTest1)
		{
			Vector2D u = { 9, -5 };
			Vector2D v = { -9, 5 };
			Vector2D add = Add(&u, &v);
			Vector2D r = { 0, 0 };
			Assert::IsTrue(Equals(&add, &r));
		}
		TEST_METHOD(AddTest2)
		{
			Vector2D u = { 20, 15 };
			Vector2D v = { -80, 30.5 };
			Vector2D add = Add(&u, &v);
			Vector2D r = { -60, 45.5 };
			Assert::IsTrue(Equals(&add, &r));
		}

		TEST_METHOD(SubstractTest1)
		{
			Vector2D u = { 9, -5 };
			Vector2D v = { 9, -5 };
			Vector2D substract = Substract(&u, &v);
			Vector2D r = { 0, 0 };
			Assert::IsTrue(Equals(&substract, &r));
		}
		 
		TEST_METHOD(SubstractTest2)
		{
			Vector2D u = { 20, 15 };
			Vector2D v = { -80, 30.5 };
			Vector2D substract = Substract(&u, &v);
			Vector2D r = { 100, -15.5 };
			Assert::IsTrue(Equals(&substract, &r));
		}

		TEST_METHOD(ScaleTest1)
		{
			Vector2D u = { 9, -5 };
			float s = 2;
			Vector2D scale = Scale(&u, s);
			Vector2D r = { 18, -10 };
			Assert::IsTrue(Equals(&scale, &r));
		}

		TEST_METHOD(ScaleTest2)
		{
			Vector2D u = { 20, 15 };
			float s = 0.5f;
			Vector2D scale = Scale(&u, s);
			Vector2D r = { 10, 7.5 };
			Assert::IsTrue(Equals(&scale, &r));
		}

		TEST_METHOD(MoveByTest1)
		{
			Vector2D u = { 9, -5 };
			Vector2D v = { -9, 5 };
			MoveBy(&u, &v);
			Vector2D r = { 0, 0 };
			Assert::IsTrue(Equals(&v, &r));
		}
		TEST_METHOD(MoveByTest2)
		{
			Vector2D u = { 20, 15 };
			Vector2D v = { -80, 30.5 };
			MoveBy(&u, &v);
			Vector2D r = { -60, 45.5 };
			Assert::IsTrue(Equals(&v, &r));
		}

		TEST_METHOD(LenghtTestAvecValeurPositif)
		{
			Vector2D u = { 2, 5 };
			float r = Length(&u);
			Assert::AreEqual(5.3851648f, r);
		}

		TEST_METHOD(LenghtTestAvecValeurNegatif)
		{
			Vector2D u = { -2, -5 };
			float r = Length(&u);
			Assert::AreEqual(5.3851648f, r);
		}

		TEST_METHOD(LenghtSqTestAvecValeurPositif)
		{
			Vector2D u = { 2, 5 };
			float r = LengthSq(&u);
			Assert::AreEqual(29.f, r);
		}

		TEST_METHOD(LenghtSqTestAvecValeurNegatif)
		{
			Vector2D u = { -2, -5 };
			float r = LengthSq	(&u);
			Assert::AreEqual(29.f, r);
		}

		TEST_METHOD(NormalizeTest1)
		{
			Vector2D u = { 2, 5 };
			bool b = Normalize(&u);
			Vector2D r = { 0.37139067f, 0.92847669f };
			Assert::IsTrue(b);
			Assert::IsTrue(Equals(&r, &u));
			Assert::AreEqual(1.f, Length(&u));
		}

		TEST_METHOD(NormalizeTest2)
		{
			Vector2D u = { 0, 0 };
			bool b = Normalize(&u);
			Assert::IsFalse(b);
		}

		TEST_METHOD(ScaleByTest1)
		{
			Vector2D u = { 9, -5 };
			float s = 2;
			ScaleBy(&u, s);
			Vector2D r = { 18, -10 };
			Assert::IsTrue(Equals(&u, &r));
		}

		TEST_METHOD(ScaleByTest2)
		{
			Vector2D u = { 20, 15 };
			float s = 0.5f;
			ScaleBy(&u, s);
			Vector2D r = { 10, 7.5 };
			Assert::IsTrue(Equals(&u, &r));
		}


		TEST_METHOD(GetVectorByAngleDegTest1)
		{
			Vector2D u = GetVectorByAngleDeg(45);
			Vector2D r = { 0.7071067, 0.7071067 };
			Assert::IsTrue(Equals(&u, &r));
		}

		TEST_METHOD(GetVectorByAngleDegTest2)
		{
			Vector2D u = GetVectorByAngleDeg(192);
			Vector2D r = { -0.9781476,  -0.2079116 };
			Assert::IsTrue(Equals(&u, &r));
		}

		TEST_METHOD(GetPolarAngleDegTest1)
		{
			Vector2D u = { -0.9781476,  -0.2079116 };
			float r = GetPolarAngleDeg(&u);
			Assert::AreEqual(168.f, r);
		}

		TEST_METHOD(GetPolarAngleDegTest2)
		{
			Vector2D u = { 0, 0 };
			float r = GetPolarAngleDeg(&u);
			Assert::AreEqual(0.f, r);
		}

		TEST_METHOD(AngleBetweenDegTest1)
		{
			Vector2D u = { -0.7193398, 0.6946583 };
			Vector2D v = { 0.6946583, 0.7193398 };
			float r = AngleBetweenDeg(&v, &u);
			Assert::AreEqual(90.f, r);
		}

		TEST_METHOD(AngleBetweenDegTest2)
		{
			Vector2D u = { -0.7193398, 0.6946583 };
			Vector2D v = { 0.6946583, 0.7193398 };
			float r = AngleBetweenDeg(&u, &v);
			Assert::AreEqual(90.f, r);
		}
	};

	TEST_CLASS(Vector3DTest)
	{
	public:
		TEST_METHOD(AddTest1)
		{
			Vector3D u = { 9, -5, 6 };
			Vector3D v = { -9, 5, -6 };
			Vector3D add = Add(&u, &v);
			Vector3D r = { 0, 0 };
			Assert::IsTrue(Equals(&add, &r));
		}

		TEST_METHOD(AddTest2)
		{
			Vector3D u = { 20, 15, 19 };
			Vector3D v = { -80, 30.5, -23 };
			Vector3D add = Add(&u, &v);
			Vector3D r = { -60, 45.5, -4 };
			Assert::IsTrue(Equals(&add, &r));
		}

		TEST_METHOD(SubstractTest1)
		{
			Vector3D u = { 9, -5, 7 };
			Vector3D v = { 9, -5, 7 };
			Vector3D substract = Substract(&u, &v);
			Vector3D r = { 0, 0, 0 };
			Assert::IsTrue(Equals(&substract, &r));
		}

		TEST_METHOD(SubstractTest2)
		{
			Vector3D u = { 20, 15, 19 };
			Vector3D v = { -80, 30.5, -23 };
			Vector3D substract = Substract(&u, &v);
			Vector3D r = { 100, -15.5, 42 };
			Assert::IsTrue(Equals(&substract, &r));
		}

		TEST_METHOD(ScaleTest1)
		{
			Vector3D u = { 9, -5, 7 };
			float s = 2;
			Vector3D scale = Scale(&u, s);
			Vector3D r = { 18, -10, 14 };
			Assert::IsTrue(Equals(&scale, &r));
		}

		TEST_METHOD(ScaleTest2)
		{
			Vector3D u = { 20, 15, 19 };
			float s = 0.5f;
			Vector3D scale = Scale(&u, s);
			Vector3D r = { 10, 7.5, 9.5 };
			Assert::IsTrue(Equals(&scale, &r));
		}

		TEST_METHOD(DotTest1)
		{
			Vector3D u = { 20, 15, 19 };
			Vector3D v = { 10, 7.5, 9.5 };
			float r = Dot(&u, &v);
			Assert::AreEqual(493.f, r);
		}

		TEST_METHOD(CrossRHTest1)
		{
			Vector3D u = { 1, 2, 3 };
			Vector3D v = { 4, 5, 6 };
			Vector3D c = CrossRH(&u, &v);
			Vector3D r = { -3, 6, -3 };
			Assert::IsTrue(Equals(&r, &c));
		}

		TEST_METHOD(CrossLHTest1)
		{
			Vector3D u = { 1, 2, 3 };
			Vector3D v = { 4, 5, 6 };
			Vector3D c = CrossLH(&u, &v);
			Vector3D r = { 3, -6, 3 };
			Assert::IsTrue(Equals(&r, &c));
		}

		TEST_METHOD(MoveByTest1)
		{
			Vector3D u = { 9, -5, 3 };
			Vector3D v = { -9, 5, -3 };
			MoveBy(&u, &v);
			Vector3D r = { 0, 0, 0 };
			Assert::IsTrue(Equals(&v, &r));
		}
		TEST_METHOD(MoveByTest2)
		{
			Vector3D u = { 20, 15, 3 };
			Vector3D v = { -80, 30.5, 6 };
			MoveBy(&u, &v);
			Vector3D r = { -60, 45.5, 9 };
			Assert::IsTrue(Equals(&v, &r));
		}

		TEST_METHOD(LenghtTest1)
		{
			Vector3D u = { 2, 5, 3 };
			float r = Length(&u);
			Assert::AreEqual(6.164414f, r);
		}

		TEST_METHOD(LenghtTest2)
		{
			Vector3D u = { -2, -5, -3 };
			float r = Length(&u);
			Assert::AreEqual(6.164414f, r);
		}

		TEST_METHOD(LenghtSqTest1)
		{
			Vector3D u = { 2, 5, 3 };
			float r = LengthSq(&u);
			Assert::AreEqual(38.f, r);
		}

		TEST_METHOD(LenghtSqTest2)
		{
			Vector3D u = { -2, -5, -3 };
			float r = LengthSq(&u);
			Assert::AreEqual(38.f, r);
		}

		TEST_METHOD(NormalizeTest1)
		{
			Vector3D u = { 2, 5, 3 };
			bool b = Normalize(&u);
			Vector3D r = { 0.324442834f, 0.811107099f, 0.486664265f };
			Assert::IsTrue(b);
			Assert::IsTrue(Equals(&r, &u));
			Assert::AreEqual(1.f, Length(&u));
		}

		TEST_METHOD(NormalizeTest2)
		{
			Vector3D u = { 0, 0, 0 };
			bool b = Normalize(&u);
			Assert::IsFalse(b);
		}

		TEST_METHOD(ScaleByTest1)
		{
			Vector3D u = { 9, -5, 3 };
			float s = 2;
			ScaleBy(&u, s);
			Vector3D r = { 18, -10, 6 };
			Assert::IsTrue(Equals(&u, &r));
		}

		TEST_METHOD(ScaleByTest2)
		{
			Vector3D u = { 20, 15, 3 };
			float s = 0.5f;
			ScaleBy(&u, s);
			Vector3D r = { 10, 7.5, 1.5f };
			Assert::IsTrue(Equals(&u, &r));
		}
	};
}