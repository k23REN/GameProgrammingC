#pragma once
#include"Component.h"
#include "Math.h"

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override final;
    void ProcessInput(const uint8_t* keyState) override{};

	/**
     * @fn
     * 加える力を合計させる
     * @brief 力を加える
     * @param (a_force) 加える力の大きさ
     * @return なし
     */
	void AddForce(const Vector2& a_force);

	///
	///取得
	///
	[[nodiscard]]const float GetAngularSpeed() const { return m_angularSpeed; }
	[[nodiscard]]const float GetForwardSpeed() const { return m_forwardSpeed; }

	///
	///設定
	///
	void SetAngularSpeed(float a_speed) { m_angularSpeed = a_speed; }
	void SetForwardSpeed(float a_speed) { m_forwardSpeed = a_speed; }
    void SetMass(float a_mass) { m_mass = a_mass; }
    void SetMaxSpeed(float a_maxSpeed) { m_maxSpeed = a_maxSpeed; }

private:
	//!回転制御
	float m_angularSpeed = 0.0f;
	//!前進運動制御
	float m_forwardSpeed = 0.0f;

	//!質量
    float m_mass = 0.1f;
    //!力の合計
    Vector2 m_sumOfForces = Vector2::Zero;
    //!速度
    Vector2 m_velocity = Vector2::Zero;
    //!加速度
    Vector2 m_acceleration;

	float m_maxSpeed = 300.0f;
};