/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:06 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/23 21:00:28 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quaternion quaternionFromAxisAngle(t_vec3 axis, double angle)
{
    t_quaternion q;
    double halfAngle = angle / 2.0;
    double sinHalfAngle = sin(halfAngle);
    q.w = cos(halfAngle);
    q.x = axis.x * sinHalfAngle;
    q.y = axis.y * sinHalfAngle;
    q.z = axis.z * sinHalfAngle;
    return q;
}

t_quaternion quaternionMultiply(t_quaternion a, t_quaternion b)
{
    t_quaternion q;
    q.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
    q.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
    q.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
    q.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
    return q;
}

t_quaternion quaternionConjugate(t_quaternion q)
{
    t_quaternion conj;
    conj.w = q.w;
    conj.x = -q.x;
    conj.y = -q.y;
    conj.z = -q.z;
    return conj;
}

t_vec3 rotateVectorWithQuaternion(t_vec3 v, t_quaternion q)
{
    t_quaternion p, conjQ;
    p.w = 0;
    p.x = v.x;
    p.y = v.y;
    p.z = v.z;
    conjQ = quaternionConjugate(q);
    p = quaternionMultiply(q, quaternionMultiply(p, conjQ));
    return (t_vec3 ) { p.x, p.y, p.z };
}

t_vec3  quaternion_rotate_by_aixs(t_vec3 orient, t_vec3 axis, double angle)
{
    t_quaternion q = quaternionFromAxisAngle(axis, angle);
    t_vec3 rotatedDirection = rotateVectorWithQuaternion(orient, q);
    
    printf("Direction vector before rotation: (%f, %f, %f)\n", orient.x, orient.y, orient.z);
    printf("Reference axis: (%f, %f, %f)\n", axis.x, axis.y, axis.z);
    printf("Angle: %f radians\n", angle);
    printf("Direction vector after rotation: (%f, %f, %f)\n", rotatedDirection.x, rotatedDirection.y, rotatedDirection.z);
    
    return rotatedDirection;
}