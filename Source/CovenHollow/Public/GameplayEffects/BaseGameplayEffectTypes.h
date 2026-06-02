#pragma once

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap UMETA(DisplayName = "ApplyOnOverlap"),
	ApplyOnEndOverlap UMETA(DisplayName = "ApplyOnEndOverlap"),
	DoNotApply UMETA(DisplayName = "DoNotApply"),

	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnEndOverlap UMETA(DisplayName = "RemoveOnEndOverlap"),
	DoNotRemove UMETA(DisplayName = "DoNotRemove"),

	MAX UMETA(Hidden)
};
